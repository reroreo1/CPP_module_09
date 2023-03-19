SRC = *.cpp

OBJ = $(SRC:.c=.o)

NAME = PmergeMe
all:	$(NAME)

$(NAME):	$(SRC)
	c++ $(SRC) -Wall -Werror -Wextra -fsanitize=address -g3 -o $(NAME) -std=c++98

clean:
				rm -f $(OBJS)
				
fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)