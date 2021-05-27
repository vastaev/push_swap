# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/05/11 19:04:57 by cjoanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

HEADER	=	push_swap.h

SRCS	=	srcs/push_swap.c\
			srcs/validation.c

OBJS	=	$(SRCS:.c=.o)

CC 		=	gcc

СFLAGS	=	-Wall -Wextra -Werror

INCDIR	=	./includes/

LIBFT	=	libs/libft/libft.a

RM		=	rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(СFLAGS) -I $(INCDIR) -c $< -o $@

$(NAME) : $(OBJS) $(INCDIR)$(HEADER)
	@$(MAKE) -C $(dir $(LIBFT))
	$(CC) $(LIBFT) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) clean -C $(dir $(LIBFT))

fclean : clean
	$(RM) $(NAME) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re