# _*_ MakeFile _*_

NAME = functions.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = check_map.c counter.c exit.c ft_close.c ft_itoa.c ft_split.c ft_strcmp.c ft_strjoin.c ft_strlen.c ft_substr.c line_checker.c 

OBJS = $(SRCS:.c=.o)

ICLS = ../so_long.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o: 
	$(CC) $(CFLAGS) -I $(ICLS) -c $<

clean : 
	rm -f $(OBJS)
	
fclean :	clean
	rm -f $(NAME) 

re : fclean all

.PHONY : clean fclean re all