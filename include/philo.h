/*
** EPITECH PROJECT, 2018
** philo.h
** File description:
** header
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <pthread.h>

typedef enum {
	RESTED,
	TIRED
} philo_state;

typedef struct philo_s {
	philo_state state;
	unsigned int nb;
	pthread_mutex_t stick;
	pthread_t thread;
	struct philo_s *next;
} philo_t;

void *live(void *);
philo_t *create_philo(int);
philo_t *create_table(int, int);
void launch_threads(philo_t*, int);
void join_threads(philo_t*, int);

#endif /* !PHILO_H_ */
