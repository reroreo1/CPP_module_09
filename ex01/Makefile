SRC = *.cpp

OBJ = $(SRC:.c=.o)

NAME = RPN
all:	$(NAME)

$(NAME):	$(SRC)
	c++ $(SRC) -Wall -Werror -Wextra -o $(NAME) -std=c++98

clean:
				rm -f $(OBJS)
				
fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)