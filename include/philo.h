/*
** EPITECH PROJECT, 2018
** philo.h
** File description:
** header
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <pthread.h>

typedef struct philo_s {
	unsigned int nb;
	pthread_mutex_t stick;
	pthread_t thread;
	struct philo_s *next;
} philo_t;

philo_t *create_philo(int);
philo_t *create_table(int, int);

#endif /* !PHILO_H_ */
