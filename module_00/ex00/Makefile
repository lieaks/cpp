SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 
# CFLAGS += -g3
# CFLAGS += -fsanitize=address
# INCLUDE = -Lincludes

NAME = megaphone 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

-include $(DEPS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

leak: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re 
