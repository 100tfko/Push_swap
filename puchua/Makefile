# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 13:06:03 by lcuevas-          #+#    #+#              #
#    Updated: 2024/02/21 09:33:39 by lcuevas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

PUSHSWAP = obj/push_swap.a

CHECKER = bonus_obj/checker.a

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =	src/actions.c\
		src/check.c\
		src/cost.c\
		src/exit.c\
		src/fill_struct.c\
		src/lst_stack.c\
		src/lst_stack_2.c\
		src/main.c\
		src/push.c\
		src/reverse_rotate.c\
		src/rotate.c\
		src/sort_three.c\
		src/swap.c\

BONUS_SRCS = bonus_src/checker.c\

OBJS = $(SRCS:src/%.c=obj/%.o)

BONUS_OBJS = $(BONUS_SRCS:bonus_src/%.c=bonus_obj/%.o)

all : $(LIBFT) $(NAME)

# .SILENT: pa silenciar echos rollo "all $(LIBFT_LIB_PATH) $(NAME) $(NAME_BONUS) $(OBJ) etc..
bonus : $(LIBFT) $(NAME_BONUS)

$(NAME):	$(OBJS) $(LIBFT)
				ar -rcs $(PUSHSWAP) $(OBJS)
				$(CC) $(CFLAGS) $(PUSHSWAP) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME_BONUS):	$(BONUS_OBJS) $(OBJS) $(LIBFT)
					ar -rcs $(CHECKER) $(BONUS_OBJS) $(OBJS)
					$(CC) $(CFLAGS) $(CHECKER) $(LIBFT) -o $(NAME_BONUS)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

bonus_obj/%.o: bonus_src/%.c
	mkdir -p bonus_obj
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	$(RM) obj
	make -C $(LIBFT_PATH) clean

fclean:
	$(RM) obj bonus_obj $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re
