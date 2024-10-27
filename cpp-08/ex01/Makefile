NAME = Span

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

CPP = c++

SRCS = main.cpp Span.cpp

OBJ = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re: clean all

.PHONY: all re clean fclean