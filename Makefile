CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

INC = -I libft -I mandatory/include -I bonus/include

SRCS_BASE = pipex.c \
			error.c \
			util.c \
			args.c
BONUS_SRCS_BASE = pipex_bonus.c \
					error_bonus.c \
					get_next_line_bonus.c \
					get_next_line_utils_bonus.c \
					util_bonus.c \
					args_bonus.c

SRCS = $(addprefix mandatory/src/, $(SRCS_BASE))
BONUS_SRCS = $(addprefix bonus/src/, $(BONUS_SRCS_BASE))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) libft.a
	$(CC) $(CFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

libft.a:
	make -C libft

bonus :
	make "OBJS = $(BONUS_OBJS)" all

clean :
	make clean -C libft
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f libft.a
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re