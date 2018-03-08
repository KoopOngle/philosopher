/*
** EPITECH PROJECT, 2018
** philosopers
** File description:
** create and initialize
*/

#include "philo.h"
#include <stdlib.h>

philo_t *create_philo(int nb_eat)
{
	philo_t *philo;

	philo = malloc(sizeof(*philo));
	if (!philo)
		return (NULL);
	philo->nb = nb_eat;
	philo->stick = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	philo->next = NULL;
	return (philo);
}

philo_t *create_table(int nb_philo, int nb_eat)
{
	int i = -1;
	philo_t *ret = create_philo(nb_eat);
	philo_t *tmp = ret;

	if (!ret)
		return (NULL);
	while (++i < nb_philo - 1) {
		tmp->next = create_philo(nb_eat);
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = ret;
	return (ret);
}
