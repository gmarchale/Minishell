# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:08:03 by noloupe           #+#    #+#              #
#    Updated: 2023/06/05 15:39:05 by gmarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

FILES		=	main.c\
				env/env.c\
				builtins/echo.c\
				libft/str_utils.c

SRCS		=	$(addprefix srcs/, $(FILES))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SANITIZE	=	-fsanitize=address -g

### LIB INCLUDES ###

#XXXXX_DIR	=	
#XXXXX		=	

#DIRS		=	$(XXXXX)

### RULES ###

$(NAME):		$(OBJS) #dirs
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "Done."

#dirs:
#				@echo "Making xxxxx..."
#				@make -C $(XXXXX_DIR)
#				@echo "Xxxxx done."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

sanitize:		$(OBJS) #dirs
				@echo "Compiling with sanitize..."
				@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) -o $(NAME)
				@echo "Done."

all:			$(NAME)

clean:
				@echo "Cleaning..."
				@rm -f $(OBJS)
				@echo "Cleaned."

fclean:			clean
				@rm -f $(NAME)

re :			fclean $(NAME)

.PHONY: sanitize all clean fclean re
