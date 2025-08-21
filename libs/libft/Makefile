# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 13:31:46 by lwillis           #+#    #+#              #
#    Updated: 2025/02/26 16:27:16 by lwillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHARS 	= $(addsuffix .c, $(addprefix char/ft_, isalnum isalpha isascii	\
							isdigit isprint))
LISTS 	= $(addsuffix .c, $(addprefix list/ft_, lstnew lstadd_front		\
							lstsize lstlast lstadd_back lstdelone lstclear	\
							lstiter	lstmap))
MATHS	= $(addsuffix .c, $(addprefix maths/ft_, pow strtof))
MEM 	= $(addsuffix .c, $(addprefix mem/ft_, bzero calloc memchr memcmp 	\
							memcpy memmove memset))
PUT 	= $(addsuffix .c, $(addprefix put/ft_, putchar_fd putendl_fd 		\
							putnbr_fd putstr_fd))
STR 	= $(addsuffix .c, $(addprefix str/ft_, atoi itoa count_array \
							free_stringlist \
							split strchr strcmp \
							strdup striteri strjoin strlcat strlcpy strlen	\
							strmapi strncmp strnstr strpos strrchr  \
							strtrim	\
							substr tolower toupper get_next_line))

SOURCES =  $(CHARS) $(LISTS) $(MATHS) $(MEM) $(PUT) $(STR)

OBJECTS = $(SOURCES:c=o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	cp $(NAME) ../$(NAME)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(@:o=c) -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
