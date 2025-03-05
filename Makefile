NAME = push_swap

NAME_BNS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = lib/libft.a

SRC = src/big_sort.c src/main.c src/moves2.c src/push_swap.c src/push_swap_utils.c \
	src/moves.c src/moves3.c src/sorts.c

SRCB = src_bns/main_bonus.c src_bns/checker_utils2_bonus.c src_bns/moves2_bonus.c \
	 src_bns/moves_bonus.c src_bns/moves3_bonus.c src_bns/checker_utils_bonus.c

GNL = src_bns/GNL/get_next_line.c src_bns/GNL/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJS = $(SRCB:.c=.o)
OBJ_GNL = $(GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJS) $(OBJ_GNL)
	make -C lib
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OBJ_GNL) -o $(NAME_BNS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_GNL)
	@$(RM) $(OBJS)
	@make clean -C lib

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BNS)
	@make fclean -C lib

re: fclean all

.PHONY: clean