/*
** EPITECH PROJECT, 2018
** live.c
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "extern.h"
#include "philo.h"

static void philo_sleep(philo_t *philo)
{
	lphilo_sleep();
	philo->state = RESTED;
}

static void think(pthread_mutex_t *mutex)
{
	lphilo_take_chopstick(mutex);
	lphilo_think();
	usleep(rand() % 500);
	if (pthread_mutex_unlock(mutex))
		lphilo_release_chopstick(mutex);
}

static void eat(philo_t *philo)
{
	lphilo_take_chopstick(&(philo->stick));
	lphilo_take_chopstick(&(philo->next->stick));
	lphilo_eat();
	usleep(rand() % 500);
	if (pthread_mutex_unlock(&(philo->stick)) == 0)
		lphilo_release_chopstick(&(philo->stick));
	if (pthread_mutex_unlock(&(philo->next->stick)) == 0)
		lphilo_release_chopstick(&(philo->next->stick));
	philo->state = TIRED;
	philo->nb -= 1;
}

static void doAction(philo_t *philo)
{
	int left;
	int right;

	if (philo->state == RESTED) {
		left = pthread_mutex_trylock(&(philo->stick));
		right = pthread_mutex_trylock(&(philo->next->stick));
		if (left == 0 && right != 0)
			think(&(philo->stick));
		else if (left != 0 && right == 0)
			think(&(philo->next->stick));
		else if (left == 0 && right == 0){
			eat(philo);
		}
	} else
		philo_sleep(philo);
}

void *live(void *arg)
{
	philo_t *philo = (philo_t*)arg;

	while (philo->nb > 0) {
		doAction(philo);
	}
	return (NULL);
}
