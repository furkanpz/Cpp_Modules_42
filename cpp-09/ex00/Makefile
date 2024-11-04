NAME = btc

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

CPP = c++

SRCS = main.cpp  BitcoinExchange.cpp

OBJ = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		$(CPP) $(FLAGS) $(OBJ) -o $(NAME)	

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re: clean all

.PHONY:all re clean fclean