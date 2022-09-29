CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

HEADER = ./pushswap.h

NAME = push_swap

OBJECTS = 	./main.o \
			./checker/checker_main.o \
			./checker/checker_utils/check_if_int.o \
			./checker/checker_utils/check_duplicates.o \
			./checker/checker_utils/link_last_nodes.o \
			./checker/checker_utils/loop_through_char_nums.o \
			./utils/ft_atoi.o \
			./utils/ft_isdigit.o \
			./utils/ft_split.o \
			./utils/ft_strlen.o \
			./utils/ft_double_strlen.o \
			./utils/ft_strlcpy.o \
			./utils/ft_memcpy.o \
			./utils/ft_putstr.o \
			./init/init_lookup.o \
			./moves/stack_moves/ft_push.o \
			./moves/stack_moves/ft_lstlast.o \
			./moves/pushswap_moves/push.o \
			./moves/pushswap_moves/rotate.o \
			./moves/pushswap_moves/reverse_rotate.o \
			./moves/pushswap_moves/swap.o \
			./sort_stack/is_sorted.o \
			./sort_stack/sort_stack_main.o \
			./init/init_stacks.o \
			./init/init_metadata.o \
			./error_management/error_display.o \
			./utils/ft_itoa.o


.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc -o $@ $^ 

$(OBJECTS): $(HEADER)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all