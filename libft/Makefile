CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c\
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strncmp.c \
	   ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	   ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c  \
	   ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_printf.c  \
	   print_hexa.c print_specifiers_a.c print_specifiers_b.c



OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADER = libft.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@ -I $(HEADER)

$(NAME): make_mandatory

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f make_bonus make_mandatory

fclean: clean
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(NAME)
	rm -f make_bonus make_mandatory

re: fclean all

bonus: make_bonus

make_mandatory: $(OBJS)
	ar rc $(NAME) $(OBJS)
	touch $@

make_bonus: $(BONUS_OBJS)
	ar rc $(NAME) $^
	touch $@

.PHONY: all clean fclean re bonus
