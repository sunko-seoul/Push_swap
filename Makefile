CC = cc
CFLAFS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = push_swap.c err.c argv_check.c deque_operation.c deque_util.c\
	   operation_push.c operation_reverse_rotate.c operation_rotate.c\
	   operation_swap.c binary_tree_1.c binary_tree_2.c binary_tree_3.c\
	   binary_search_tree.c avl_rebalance_1.c avl_rebalance_2.c index.c\
	   check.c sorting_hard_special.c divide.c divide_util.c\
	   sorting_hard_five_special.c sorting_hard_general.c divide_recursion.c\
	   sorting_hard_five_general.c divide_setting_info.c divide_recursion_util.c\
	   divide_core.c sorting_hard_six_general.c sorting_hard_seven_general.c\
	   divide_recursion_hardsort.c sorting_hard_eight_general.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
HEADER = push_swap.h

LIB = ft
LIBPATH = libft

all: $(NAME)

bonus: make_bonus

$(NAME): $(OBJS)
	@make -C ./libft make_mandatory
	$(CC) $(CFLAFS) -o $@ $^ -I $(HEADER) -L$(LIBPATH) -l$(LIB)

%.o: %.c
	$(CC) $(CFLAFS) -c $< -o $@

clean:
	@make -C ./libft clean
	rm -f make_mandatory make_bonus
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean:
	@make -C ./libft fclean
	rm -f make_mandatory make_bonus
	rm -f $(OBJS) $(NAME)
	rm -f $(BONUS_OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

