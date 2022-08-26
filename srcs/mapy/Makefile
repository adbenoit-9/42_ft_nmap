# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 18:17:27 by adbenoit          #+#    #+#              #
#    Updated: 2022/08/26 11:02:06 by leon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2
DEPFLAGS = -MP -MD

UNAME	:= $(shell uname)
ifeq ($(UNAME), Darwin)
	CFLAGS += -DMAC
endif

MODULES		:= ../nmap/incs \

IFLAGS		:= $(foreach D,$(MODULES), -I$(D))

SRC			:= mapy.c \
				sety_f.c \
				exey_f.c

BUILD 		:= .build
OBJ_DIR 	:= $(BUILD)/obj
ASM_DIR 	:= $(BUILD)/asm

OBJ			:= $(SRC:%.c=$(OBJ_DIR)/%.o)
ASM			:= $(SRC:%.c=$(ASM_DIR)/%.s)

NAME	:= mapy.a

all : $(NAME) 

$(NAME): $(OBJ) $(ASM)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"

$(BUILD):
	@mkdir $@ $(OBJ_DIR) $(ASM_DIR)

$(OBJ_DIR)/%.o:%.c | $(BUILD)
	@$(CC) $(CFLAGS)  $(IFLAGS) $(DEPFLAGS) -c -o $@ $^ 

$(ASM_DIR)/%.s:%.c | $(BUILD)
	@$(CC) $(CFLAGS) $(OPTFLAGS) $(IFLAGS) -S -o $@ $^ 

debug: CFLAGS += -DDEBUG -fsanitize=thread -g3
debug: re

clean:
	@rm -Rf $(BUILD)

fclean: clean
	@rm -Rf $(NAME)

release: clean
	@tar zcvf release.tgz *
gstats:
	@git status

gdiff:
	@git diff --color --stat

spec: $(OBJ)
	@$(CC) -o $@ $(OBJ) -fdump-ada-spec
	@mkdir -f ads
	@mv *.ads ads
	
re: fclean all

.PHONY: all clean fclean re debug
