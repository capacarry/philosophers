NAME = philo
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
SRC = src/philo.c utils/ft_atoi.c utils/parsing.c utils/get_time.c

$(NAME): $(OBJS)

		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;32m✅ FILES COMPILED ✅\033[0m"

all: $(NAME) 

clean:
    
	$(RM) $(OBJS)

fclean: clean
    
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re