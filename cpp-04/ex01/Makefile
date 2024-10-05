NAME = Brain

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

CPP = c++

SRCPATH = ./src

INC = ./inc

SRCS = $(SRCPATH)/main.cpp $(SRCPATH)/Animal.cpp \
 $(SRCPATH)/Dog.cpp $(SRCPATH)/Cat.cpp \
 $(SRCPATH)/WrongAnimal.cpp $(SRCPATH)/WrongCat.cpp \
 $(SRCPATH)/Brain.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -I$(INC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean