# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <alngo@student.42.fr>                +#+  +:+       +#+         # #                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 21:33:03 by alngo             #+#    #+#              #
#    Updated: 2017/11/28 17:54:31 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SUB_PATH = /{type,mem,assert}
SRC_NAME = 	assert/ft_assert.c\
		assert/ft_test.c\
		type/ft_ctype.c\
		type/ft_isalnum.c\
		type/ft_isalpha.c\
		type/ft_iscntrl.c\
		type/ft_isdigit.c\
		type/ft_isgraph.c\
		type/ft_islower.c\
		type/ft_isprint.c\
		type/ft_ispunct.c\
		type/ft_isspace.c\
		type/ft_isupper.c\
		type/ft_isxdigit.c\
		type/ft_tolower.c\
		type/ft_toupper.c\
		mem/ft_memset.c\
		mem/ft_bzero.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj
SRC_PATH = src
INCLUDE_PATH = include

TEST_NAME = test
TEST_LIB = libft.a
TEST_SRC = main.c

LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)assembling...$(LOG_NOCOLOR)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(LOG_CLEAR)$(NAME)... $(LOG_GREEN)Done !$(LOG_NOCOLOR)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)$(SUB_PATH) 2> /dev/null || true

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) -I $(INCLUDE_PATH) -MMD -MP -c $< -o $@

clean:
	$(RM) -r $(OBJ_PATH)

fclean:	clean
	$(RM) -r $(NAME)
	$(RM) -r $(TEST_NAME)

re:	fclean all

test: ${NAME}
	@${CC} -o $(TEST_NAME) $(CFLAGS) -I $(INCLUDE_PATH) $(SRC_PATH)/$(TEST_SRC) $(TEST_LIB)
	@./test

-include $(OBJ:.o=.d)
