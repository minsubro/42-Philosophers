CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = av_check.c		\
	   fork_init.c			\
	   memory.c				\
	   monitoring.c			\
	   philo_action.c		\
	   philo_fork_action.c	\
	   philo_init.c			\
	   philo_main.c			\
	   simualtion.c			\
	   time.c				

NAME = philo
OBJS = $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

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