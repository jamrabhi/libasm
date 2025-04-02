# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 01:17:01 by jamrabhi          #+#    #+#              #
#    Updated: 2025/04/02 21:10:56 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

NASM = nasm

NASM_FLAGS = -f elf64

SRC_DIR = src

SRC_FILES = hello_world.s

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ = $(SRC:.c=.o)

S_OBJ = $(SRC:.s=.o)

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME) : $(S_OBJ)
	@echo "Compiling libasm ..."
	@ar rcs $(NAME) $(S_OBJ)
	@echo "DONE\n"

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

.s.o:
	@$(NASM) $(NASM_FLAGS) $(SRC)

clean:
	@echo "Deleting libasm objects files ..."
	@rm -f $(S_OBJ)
	@echo "DONE"

fclean: clean
	@echo "Deleting libasm's binary ..."
	@rm -f $(NAME) test
	@echo "DONE"

re: fclean
	@make all

test: $(NAME)
	@$(CC) $(CFLAGS) main.c -L. -lasm -o test
