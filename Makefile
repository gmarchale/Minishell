# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:08:03 by noloupe           #+#    #+#              #
#    Updated: 2023/09/04 17:43:07 by gmarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

FILES		=	main.c\
				builtins/tester.c\
				builtins/cmd_utils.c\
				builtins/echo.c\
				builtins/cd.c\
				builtins/pwd.c\
				builtins/export.c\
				builtins/unset.c\
				builtins/env.c\
				builtins/exit.c\
				env/env.c\
				exec/exec.c\
				libft/str_utils.c\
				parser/lexer.c\
				parser/lexer_utils.c\
				parser/lex_list.c\
				parser/mini_utils.c\
				parser/parser.c\
				parser/parser_utils.c\
				parser/parser_lst.c\
				signal.c\
				heredoc.c\

SRCS		=	$(addprefix srcs/, $(FILES))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

READL		=	-L/usr/local/lib -I/usr/local/include -lreadline -L $(shell brew --prefix readline)/lib -I $(shell brew --prefix readline)/include

SANITIZE	=	-fsanitize=address -g

### LIB INCLUDES ###

LIBFT_DIR	=	srcs/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	srcs/ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

DIRS		=	$(PRINTF) $(LIBFT)

### RULES ###

$(NAME):		$(OBJS)
				@echo "Making libft..."
				@make bonus -C $(LIBFT_DIR)
				@echo "Libft done."
				@echo "Making printf..."
				@make -C $(PRINTF_DIR)
				@echo "Printf done."
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) $(DIRS) $(READL) -o $(NAME)
				@echo "Done."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

sanitize:		$(OBJS)
				@echo "Making libft..."
				@make bonus -C $(LIBFT_DIR)
				@echo "Libft done."
				@echo "Making printf..."
				@make -C $(PRINTF_DIR)
				@echo "Printf done."
				@echo "Compiling with sanitize..."
				@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) $(DIRS) $(READL) -o $(NAME)
				@echo "Done."

all:			$(NAME)

clean:
				@echo "Cleaning..."
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(PRINTF_DIR)
				@rm -f $(OBJS)
				@echo "Cleaned."

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(PRINTF_DIR)
				@rm -f $(NAME)

re :			fclean $(NAME)

.PHONY: sanitize all clean fclean re
