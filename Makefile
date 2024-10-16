SRCS = ft_main.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
libftdir = libft
libftname = libft.a
LIBFT_OBJS = $(shell find $(libftdir) -name '*.o')

all: $(NAME)

libft:
	$(MAKE) -C $(libftdir) bonus

$(NAME): libft $(OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(libftdir) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(libftdir) fclean

re: fclean $(NAME)
	$(MAKE) -C $(libftdir) re

.PHONY: all clean fclean re libft
