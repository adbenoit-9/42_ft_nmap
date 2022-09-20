# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 18:17:27 by adbenoit          #+#    #+#              #
#    Updated: 2022/09/20 11:49:06 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc-10

CFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2
DEPFLAGS = -MP -MD

UNAME	:= $(shell uname)
ifeq ($(UNAME), Darwin)
	CFLAGS += -DMAC
endif

MODULES	:= ../mapy\
			../nmap/incs\
			../proty

IFLAGS = $(foreach D,$(MODULES), -I$(D))

SRC			:= analysy_synscan.c\
				analysy_udpscan.c\
				analysy_ackscan.c\
				analysy_fnxscan.c\
				analysy_icmp.c

BUILD 		:= .build
OBJ_DIR 	:= $(BUILD)/obj
ASM_DIR 	:= $(BUILD)/asm

OBJ			:= $(SRC:%.c=$(OBJ_DIR)/%.o)
ASM			:= $(SRC:%.c=$(ASM_DIR)/%.s)

NAME	:= analysy.a

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
