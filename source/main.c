/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int nb_philo = 0;
	int nb_eat = 0;

	if (argc < 5 || !isdigit(argv[2][0]) || !isdigit(argv[4][0]))
		printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\nDESCRIPTION\n\t"
		"-p nbr_p\t number of philosophers\n\t-e nbr_e\t maximum numbe"
		"r times a philosopher eats before exiting the program\n");
	if (strcmp(argv[1],"-e"))
		nb_eat = atoi(argv[2]);
	else if (strcmp(argv[1],"-p"))
		nb_philo = atoi(argv[2]);
	else {
		printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\nDESCRIPTION\n\t"
		"-p nbr_p\t number of philosophers\n\t-e nbr_e\t maximum numbe"
		"r times a philosopher eats before exiting the program\n");
		exit(84);
	}
	if (strcmp(argv[3],"-e"))
		nb_eat = atoi(argv[4]);
	else if (strcmp(argv[3],"-p"))
		nb_philo = atoi(argv[4]);
	else {
		printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\nDESCRIPTION\n\t"
		"-p nbr_p\t number of philosophers\n\t-e nbr_e\t maximum numbe"
		"r times a philosopher eats before exiting the program\n");
		exit(84);
	}
}
