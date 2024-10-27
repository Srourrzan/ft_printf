SRCS = ft_main.c ft_utils.c ft_support_print.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
libftdir = libft
libftname = libft.a
LIBFT_OBJS = $(libftdir)/ft_isalnum.o $(libftdir)/ft_isprint.o $(libftdir)/ft_memcmp.o $(libftdir)/ft_putchar_fd.o $(libftdir)/ft_split.o \
       $(libftdir)/ft_strlcat.o $(libftdir)/ft_strncmp.o $(libftdir)/ft_substr.o $(libftdir)/ft_atoi.o $(libftdir)/ft_isalpha.o \
       $(libftdir)/ft_itoa.o $(libftdir)/ft_memcpy.o $(libftdir)/ft_putendl_fd.o $(libftdir)/ft_strchr.o $(libftdir)/ft_strlcpy.o \
       $(libftdir)/ft_strnstr.o $(libftdir)/ft_tolower.o $(libftdir)/ft_bzero.o $(libftdir)/ft_isascii.o $(libftdir)/ft_memcpy.o \
       $(libftdir)/ft_putnbr_fd.o $(libftdir)/ft_strdup.o $(libftdir)/ft_strlen.o $(libftdir)/ft_strrchr.o $(libftdir)/ft_memset.o \
       $(libftdir)/ft_toupper.o $(libftdir)/ft_calloc.o $(libftdir)/ft_isdigit.o $(libftdir)/ft_memchr.o $(libftdir)/ft_memmove.o \
       $(libftdir)/ft_putstr_fd.o $(libftdir)/ft_strjoin.o $(libftdir)/ft_strmapi.o $(libftdir)/ft_strtrim.o $(libftdir)/ft_striteri.o \
		$(libftdir)/ft_lstadd_back.o $(libftdir)/ft_lstadd_front.o $(libftdir)/ft_lstclear.o \
        $(libftdir)/ft_lstdelone.o $(libftdir)/ft_lstlast.o $(libftdir)/ft_lstnew.o \
        $(libftdir)/ft_lstsize.o $(libftdir)/ft_lstiter.o $(libftdir)/ft_lstmap.o

# LIBFT_OBJS = $(shell find $(libftdir) -name '*.o')

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
