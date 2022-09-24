CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = philo_bonus_main.c	\
	   ft_atoi_bonus.c		\
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