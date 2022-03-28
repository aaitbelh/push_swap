Name = push_swap
Name1 = checker
LIBFT_PATH = libft/libft.a
LIBFT = libft
PATH_CHECK = ./check/
Header = push_swap.h
SRCS = push_swap.c actions.c actions_2.c actions_tools.c functions.c get_best.c more_functions.c \
		push_b.c sort_three.c error_management.c

SRCS_B  = $(PATH_CHECK)checker.c $(PATH_CHECK)checker_tools.c $(PATH_CHECK)get_next_line.c $(PATH_CHECK)checker_actions.c \
		$(PATH_CHECK)checker_actions2.c $(PATH_CHECK)checker_actions_tools.c $(PATH_CHECK)ft_split.c \
		$(PATH_CHECK)ft_atoi.c $(PATH_CHECK)tools.c $(PATH_CHECK)errors_check.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(Name)

$(Name) : $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT_PATH) -o $(Name)
	@echo "\033[92m ALL FILES ARE MAEKED\033[0m"

bonus : all
	@$(CC) $(CFLAGS) $(SRCS_B) $(LIBFT_PATH) -o $(Name1)

 %.o : %.c
	@$(CC) $(CFLAGS) -c $<

clean : 
	@make clean -C  $(LIBFT)
	@rm -f $(OBJS) $(OBJS_B)
	@echo "\033[31m ALL FILEES ARE CLEANED\033[60m"

fclean : clean
	@make fclean -C $(LIBFT)
	@rm -f $(Name)
	@rm -f $(Name1)
	@echo "\033[34m AND THE PROGRAM IS DELETED\033[0m"

re : fclean all