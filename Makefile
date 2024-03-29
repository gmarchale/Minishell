# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:08:03 by noloupe           #+#    #+#              #
#    Updated: 2023/09/21 14:23:27 by noloupe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

FILES		=	main.c\
				builtins/cmd_utils.c\
				builtins/echo.c\
				builtins/cd.c\
				builtins/pwd.c\
				builtins/export.c\
				builtins/unset.c\
				builtins/env.c\
				builtins/exit.c\
				env/env.c\
				env/env_utils.c\
				exec/exec.c\
				exec/exec_builtins.c\
				exec/get_path.c\
				exec/link_pipes.c\
				exec/make_env_list.c\
				exec/perror_exit.c\
				exec/pids.c\
				exec/pipes_utils.c\
				exec/solo_fds.c\
				libft/str_utils.c\
				parser/lexer.c\
				parser/lexer_utils.c\
				parser/lex_list.c\
				parser/mini_utils.c\
				parser/parser.c\
				parser/lst_to_cmd.c\
				parser/lst_types.c\
				parser/copy_key_value.c\
				parser/expander_utils.c\
				parser/expand.c\
				parser/get_env_value_size.c\
				parser/expander.c\
				parser/heredoc.c\
				signal.c\
				sig_utils.c\

SRCS		=	$(addprefix srcs/, $(FILES))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SANITIZE	=	0

READL		=	-L/usr/local/lib -I/usr/local/include -lreadline -L $(shell brew --prefix readline)/lib -I $(shell brew --prefix readline)/include

ifeq ($(SANITIZE), 1)
	CFLAGS	+= -fsanitize=address -g3
endif


### LIB INCLUDES ###

LIBFT_DIR	=	srcs/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	srcs/ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

DIRS		=	$(PRINTF) $(LIBFT)

### RULES ###

$(NAME):		$(OBJS)
				@echo "Making libft..."
				@make -C $(LIBFT_DIR)
				@echo "Libft done."
				@echo "Making printf..."
				@make -C $(PRINTF_DIR)
				@echo "Printf done."
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) $(DIRS) $(READL) -o $(NAME)
				@echo "Done."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				
all:			$(NAME)

sanitize:		fclean
				@echo "Compiling with sanitize..."
				@make SANITIZE=1

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
