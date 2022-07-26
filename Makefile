# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 13:52:52 by amateo-r          #+#    #+#              #
#    Updated: 2022/05/13 16:40:38 by amateo-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
# https://www.programiz.com/dsa/linked-list

#	SOURCES
SRC			=	./src/main.c \
				./src/exceptions_handlers.c \
				./src/stacks_handler.c \
				./src/psutils_00.c \
				./src/pop.c \
				./src/swap.c \
				./src/push.c \
				./src/rotate.c \
				./src/reverse.c \
				./src/quickselect.c \
				./src/quicksort.c \
				./src/partition.c \
				./src/trash.c \
				./src/shortsort.c
OBJ			=	$(SRC:.c=.o)

#	LIBS
LIBFT		=	$(LIBFT_PATH)/libft.a
LIBFT_PATH	=	./include/libft

#	COMPILER
NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
RM			=	rm -f

all:		makelib $(NAME)

.%o.%c:		$(CC) $(CFLAGS) $<	-o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o	$(NAME)

makelib:
			@make bonus -C $(LIBFT_PATH)

norme:
			@echo "---- SRC ----"
			@norminette ./src
			# @echo "---- INCLUDE ----"
			# @norminette ./include

clean:
			@make -C $(LIBFT_PATH) clean
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean all
