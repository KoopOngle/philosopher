/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "extern.h"
#include "philo.h"

void print_usage()
{
	fprintf(stderr, "USAGE\n\t./philo -p nbr_p -e nbr_e\n\nDESCRIPTION\n\t"
	"-p nbr_p\t number of philosophers\n\t-e nbr_e\t maximum numbe"
	"r times a philosopher eats before exiting the program\n");
	exit(84);
}

void check_args_2(char **argv, int *nb_eat, int *nb_philo)
{
	if (strcmp(argv[3],"-e") == 0)
		*nb_eat = atoi(argv[4]);
	else if (strcmp(argv[3],"-p") == 0)
		*nb_philo = atoi(argv[4]);
	else
		print_usage();
}

void check_args(char **argv, int *nb_eat, int *nb_philo)
{
	if (strcmp(argv[1],"-e") == 0)
		*nb_eat = atoi(argv[2]);
	else if (strcmp(argv[1],"-p") == 0)
		*nb_philo = atoi(argv[2]);
	else
		print_usage();
	check_args_2(argv, nb_eat, nb_philo);
}

int main(int argc, char** argv)
{
	int nb_philo = 0;
	int nb_eat = 0;
	philo_t *table;

	RCFStartup(argc, argv);
	if (argc != 5 || !isdigit(argv[2][0]) || !isdigit(argv[4][0]))
		print_usage();
	check_args(argv, &nb_eat, &nb_philo);
	table = create_table(nb_philo, nb_eat);
	if (!table)
		return (84);
	launch_threads(table, nb_philo);
	join_threads(table, nb_philo);
	RCFCleanup();
	return (0);
}
