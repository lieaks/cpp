SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
# DEPS = $(SRCS:.cpp=.d)

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 
# CFLAGS += MMD
# CFLAGS += -g3
# CFLAGS += -fsanitize=address
INCLUDE = -I. 

NAME = fixed

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

# -include $(DEPS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

leak: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re 
