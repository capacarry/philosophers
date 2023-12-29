NAME = philo
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
OBJS = $(SRC:.c=.o)
SRC = src/main.c parse/ft_atoi.c parse/parsing.c  src/initiate_data.c utils/get_time.c utils/thread_and_mutex.c utils/status_update.c src/dinner.c utils/free_everything.c

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