# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 01:17:01 by jamrabhi          #+#    #+#              #
#    Updated: 2025/04/09 19:11:12 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

TEST = test

CC = cc

CFLAGS = -Wall -Wextra -Werror

NASM = nasm

NASM_FLAGS = -f elf64

SRC_DIR = .

SRC_FILES = main.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

SRC_ASM_DIR = src

SRC_ASM_FILES =	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s \
				ft_strdup.s

SRC_ASM = $(addprefix $(SRC_ASM_DIR)/,$(SRC_ASM_FILES))

OBJ = $(SRC:.c=.o)

ASM_OBJ = $(SRC_ASM:.s=.o)

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME) : $(ASM_OBJ)
	@echo "Compiling libasm ..."
	@ar rcs $(NAME) $(ASM_OBJ)
	@echo "DONE"

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

.s.o:
	@$(NASM) $(NASM_FLAGS) $< -o $@

clean:
	@echo "Deleting libasm objects files ..."
	@rm -f $(ASM_OBJ) $(OBJ)
	@echo "DONE"

fclean: clean
	@echo "Deleting libasm's binary ..."
	@rm -f $(NAME) $(TEST)
	@echo "DONE"

re: fclean
	@make all

test: $(NAME) $(OBJ)
	@echo "Compiling test file ..."
	@$(CC) $(CFLAGS) $(OBJ) -L. -lasm -o $(TEST)
	@echo "DONE"
