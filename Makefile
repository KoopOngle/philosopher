##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for philosopher project
##

CC		=		gcc

CFLAGS		+=		-W -Wall -Wextra

CFLAGS		+=		-I./include

CFLAGS		+=		$(DEBUG)

LDFLAGS		=		

NAME		=		philo

SRCDIR		=		source

SRCS		=		$(addprefix $(SRCDIR)/,	\
				main.c)
OBJDIR		=		build

OBJS		=		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o,  $(SRCS))

all:		$(NAME)
		@echo "Done compiling $(NAME)"

$(NAME):	buildrepo $(OBJS)
		@echo "Linking $(NAME)"
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
		@echo "->" $<
		@$(CC) -c $< -o $@ $(CFLAGS)

tests_run:
		@[ -d tests ] && make --no-print-directory -C tests || echo -n

buildrepo:
		@$(call build-repo)

clean:
		@echo "Cleaning object files"
		@rm -rf $(OBJDIR)


fclean:		clean
		@echo "Cleaning binary"
		@rm -f $(NAME)

re:		fclean all

define build-repo
	for dir in $(dir $(OBJS));	\
	do				\
		mkdir -p $$dir;		\
	done
endef

.PHONY: all tests_run buildrepo clean fclean re
