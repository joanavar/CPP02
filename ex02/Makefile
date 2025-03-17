# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joannavarrogomez <joannavarrogomez@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 12:54:59 by joanavar          #+#    #+#              #
#    Updated: 2025/03/17 18:53:07 by joannavarro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Fixed
SRCS		=	Fixed.cpp\
				Main.cpp

CC			=	c++

INCLUDES    = -I ./

RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

OBJS		=	$(SRCS:.cpp=.o)

%.o: %.cpp
		@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME) : $(OBJS) 
		@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES)
		@echo '$(NAME) compiled'
fclean: clean
		@$(RM) $(NAME)
clean: 
		@$(RM) $(OBJS)

re: fclean all

.PHONY	: all clean fclean re


