# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/05/28 03:56:01 by cjoanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS		=	push_swap
NAME_CH		=	checker

SRCS_LIST	=	validation.c\
				utils.c\
				utils_stack.c\
				utils_validation.c\
				commands.c\
				swap.c\
				push.c\
				reverse_rotate.c\
				rotate.c\
				solve.c\
				solve_utils.c\
				for_free.c\
				solve_direction.c\
				solve_small.c
SRCS_DIR	=	srcs/
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

SRCS_LIST_PS		=	push_swap.c
SRCS_LIST_CH		=	checker.c\
						get_next_line.c\
						get_next_line_utils.c\
						checker_utils.c

OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_LIST_PS =	$(patsubst %.c, %.o, $(SRCS_LIST_PS))
OBJS_LIST_CH =	$(patsubst %.c, %.o, $(SRCS_LIST_CH))

OBJS_DIR	=	objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))
OBJS_PS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST_PS))
OBJS_CH		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST_CH))

CC 			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I$(LIBFT_HEADER) -I$(HEADERS_DIR)

LIBFT_DIR = ./libs/libft/
LIBFT_HEADER = $(LIBFT_DIR)includes/
LIBFT		=	$(LIBFT_DIR)libft.a

HEADERS_DIR =	./includes/
HEADERS_LIST =	push_swap.h
HEADERS =	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

LIBRARIES = -lft -L$(LIBFT_DIR)

RM			=	rm -rf

# COLORS
GREEN = \033[0;32m
BLUE= \033[0;34m
RED = \033[0;31m
RESET = \033[0m
LIBA = libft.a

all : $(NAME_PS) $(NAME_CH)

$(NAME_CH) : $(LIBFT) $(OBJS_DIR) $(OBJS) $(OBJS_CH)
	@$(CC) $(LIBFT) $(LIBRARIES) $(INCLUDES) $(OBJS) $(OBJS_CH) -o $(NAME_CH)
	@echo "\n$(NAME_CH): $(BLUE)$(NAME_CH) object files were created$(RESET)"
	@echo "$(NAME_CH): $(GREEN)$(NAME_CH) was created$(RESET)"

$(NAME_PS) : $(LIBFT) $(OBJS_DIR) $(OBJS) $(OBJS_PS)
	@$(CC) $(LIBFT) $(LIBRARIES) $(INCLUDES) $(OBJS) $(OBJS_PS) -o $(NAME_PS)
	@echo "\n$(NAME_PS): $(BLUE)$(NAME_PS) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) was created$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) -g $(СFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)`ruby -e "puts (0..1).to_a.shuffle.join('')"`$(RESET)\c"

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME_PS): $(BLUE)creating $(NAME_PS)$(RESET)"

$(LIBFT):
	@echo "$(NAME_PS): $(BLUE)creating $(LIBA)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

clean :
	@$(RM) $(OBJS_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(NAME_PS): $(RED)object files were deleted$(RESET)"

fclean : clean
	@$(RM) $(NAME_PS)
	@echo "$(NAME_PS): $(RED)$(NAME_PS) was deleted$(RESET)"
	@$(RM) $(NAME_CH)
	@echo "$(NAME_CH): $(RED)$(NAME_CH) was deleted$(RESET)"
	@$(RM) $(LIBFT)
	@echo "$(NAME_PS): $(RED)$(LIBA) was deleted$(RESET)"

re : fclean all

.PHONY : all clean fclean re