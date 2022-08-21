# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 18:17:27 by adbenoit          #+#    #+#              #
#    Updated: 2022/08/21 18:27:42 by adbenoit         ###   ########.fr        #
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

MODULES	:= ../mapy\
			../nmap\
			../proty

IFLAGS = $(foreach D,$(MODULES), -I$(D))

SRC = buildy_ipv4_tcp.c\
		buildy_utils.c
# buildy_ipv4_udp.c\
# buildy_ipv6_tcp.c\
# buildy_ipv6_udp.c

BUILD 		:= .build
OBJ_DIR 	:= $(BUILD)/obj
ASM_DIR 	:= $(BUILD)/asm

OBJ			:= $(SRC:%.c=$(OBJ_DIR)/%.o)
ASM			:= $(SRC:%.c=$(ASM_DIR)/%.s)

NAME	:= buildy.a

all : $(NAME) 

$(NAME): $(OBJ) $(ASM)
	@ar rc $(NAME) $(OBJ)
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"

$(BUILD):
	@mkdir $@ $(OBJ_DIR) $(ASM_DIR)

$(OBJ_DIR)/%.o:%.c | $(BUILD)
	@$(CC) $(CFLAGS)  $(IFLAGS) $(DEPFLAGS) -c -o $@ $^ 

$(ASM_DIR)/%.s:%.c | $(BUILD)
	@$(CC) $(CFLAGS) $(OPTFLAGS) $(IFLAGS) -S -o $@ $^ 


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

debug:
	@echo $(ASM)



#
# 			-mtune broadwell
#		src/ft_strlen.c
# LIBS = 
# CODEDIRS =. 
#	./src
# CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
#OBJS = $(pathsubst %.c,%.o,$(SRCS))
# install:
# flash:
