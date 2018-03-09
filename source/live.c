/*
** EPITECH PROJECT, 2018
** live.c
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "extern.h"
#include "philo.h"

static void philo_sleep(philo_t *philo)
{
	lphilo_sleep();
	philo->state = RESTED;
}

static void think(philo_t *philo)
{
	pthread_mutex_lock(&(philo->stick));
	lphilo_take_chopstick(&(philo->stick));
	lphilo_think();
	if (pthread_mutex_unlock(&(philo->stick)) == 0)
		lphilo_release_chopstick(&(philo->stick));
	philo->state = HUNGRY;
}

static void eat(philo_t *philo)
{
	int a = pthread_mutex_trylock(&(philo->stick));
	int b = pthread_mutex_trylock(&(philo->next->stick));
	if (a != 0 || b != 0) {
		if (a == 0)
			pthread_mutex_unlock(&(philo->stick));
		else
			pthread_mutex_unlock(&(philo->next->stick));
		return;
	}
	lphilo_take_chopstick(&(philo->stick));
	lphilo_take_chopstick(&(philo->next->stick));
	lphilo_eat();
	if (pthread_mutex_unlock(&(philo->stick)) == 0)
		lphilo_release_chopstick(&(philo->stick));
	if (pthread_mutex_unlock(&(philo->next->stick)) == 0)
		lphilo_release_chopstick(&(philo->next->stick));
	philo->state = TIRED;
	philo->nb -= 1;
}

static void doAction(philo_t *philo)
{
	switch (philo->state) {
		case TIRED:
			philo_sleep(philo);
			break;
		case RESTED:
			think(philo);
			break;
		case HUNGRY:
			eat(philo);
			break;
	}
}

void *live(void *arg)
{
	philo_t *philo = (philo_t*)arg;

	while (philo->nb > 0) {
		doAction(philo);
	}
	return (NULL);
}
