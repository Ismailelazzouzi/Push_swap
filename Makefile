NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = main \
		creat_stack \
		Error \
		ft_split \
		manage_args \
		push_swap_magic \
		push \
		reverse_rotate \
		rotate \
		sort_three \
		swap \
		utils_1 \
		utils \
		utils2 \
		utils3 \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean