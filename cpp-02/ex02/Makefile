NAME = fixed

FLAGS = -Wall -Wextra -Werror

CPP = c++

RM = rm -rf

SRCS = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean