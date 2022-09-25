CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = create_info_bonus.c	\
	   die_check_bonus.c	\
	   ft_atoi_bonus.c		\
	   ft_itoa_bonus.c		\
	   main_action_bonus.c	\
	   make_philo_bonus.c	\
	   philo_action_bonus.c	\
	   philo_main_bonus.c	\
	   philo_utils_bonus.c	\
	   routine_bonus.c		\
	   time_bonus.c	

NAME = philo_bonus
OBJS = $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $(NAME) -lpthread

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re