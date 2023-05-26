# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 11:30:11 by noloupe           #+#    #+#              #
#    Updated: 2023/03/24 16:40:05 by noloupe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRCS			=	ft_isalpha.c\
					ft_isdigit.c\
					ft_isalnum.c\
					ft_isascii.c\
					ft_isprint.c\
					ft_strlen.c\
					ft_memset.c\
					ft_bzero.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_strlcpy.c\
					ft_strlcat.c\
					ft_toupper.c\
					ft_tolower.c\
					ft_strchr.c\
					ft_strrchr.c\
					ft_strncmp.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_strnstr.c\
					ft_atoi.c\
					ft_calloc.c\
					ft_strdup.c\
					ft_substr.c\
					ft_strjoin.c\
					ft_strtrim.c\
					ft_split.c\
					ft_itoa.c\
					ft_strmapi.c\
					ft_striteri.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					strjoin_free1.c\

SRCS_BONUS		=	ft_lstnew_bonus.c\
					ft_lstadd_front_bonus.c\
					ft_lstsize_bonus.c\
					ft_lstlast_bonus.c\
					ft_lstadd_back_bonus.c\
					ft_lstdelone_bonus.c\
					ft_lstclear_bonus.c\
					ft_lstiter_bonus.c\
					ft_lstmap_bonus.c\

OBJS			=	$(SRCS:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rc	$(NAME) $(OBJS)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			@rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean	all

bonus:		all $(OBJS_BONUS)
			@ar -rc $(NAME) $(OBJS_BONUS)

.PHONY:		all clean fclean re bonus
