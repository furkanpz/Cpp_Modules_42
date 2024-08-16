NAME = attack

FLAGS = -std=c++98 -Wall -Wextra -Werror

CPP = c++

RM = rm -rf

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean