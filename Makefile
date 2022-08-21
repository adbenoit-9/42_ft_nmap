# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 16:29:13 by adbenoit          #+#    #+#              #
#    Updated: 2022/08/21 18:15:33 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g3 #-fsanitize=address -g3
OPTFLAGS = -O2  
DEPFLAGS = -MP -MD
	 	 
IFLAGS 	= $(foreach D,$(INC_DIR), -I$(D))

UNAME	:= $(shell uname)
ifeq ($(UNAME), Darwin)
	CFLAGS += -DMAC
endif

SRC_DIR 		:= srcs

## LIBRARIES
LIBFT_DIR		:= $(SRC_DIR)/libft
BUILD_DIR		:= $(SRC_DIR)/buildy
CLEAN_DIR		:= $(SRC_DIR)/cleany
SEND_DIR		:= $(SRC_DIR)/sendy
SETUP_DIR		:= $(SRC_DIR)/setupy
REC_DIR			:= $(SRC_DIR)/recy
LIB_NAMES		:= $(LIBFT_DIR)/libft.a
# $(BUILD_DIR)/buildy.a\
# $(CLEAN_DIR)/cleany.a\
# $(SEND_DIR)/sendy.a\
# $(SETUP_DIR)/setupy.a

# MAIN
BUILD 			:= .build
OBJ_DIR 		:= $(BUILD)/obj
ASM_DIR 		:= $(BUILD)/asm
PROC_DIR 		:= $(BUILD)/proc
SUB_DIR			:= buildy\
					cleany\
					libft\
					mapy\
					nmap\
					parsing\
					prompty\
					proty\
					recy\
					sendy\
					setupy
INC_DIR 		:= $(addprefix $(SRC_DIR)/, $(SUB_DIR))\
					$(SRC_DIR)/libft/inc
					
DIRS			:= $(OBJ_DIR) $(ASM_DIR) $(PROC_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))


# FILES
NAME			:= ft_nmap
SRC				:=

# SUB_SRC			:= parser.c \
# 					parse_ip.c \
# 					parse_scan.c \
# 					parse_ports.c \
# 					parse_speedup.c \
# 					ft_isnumber.c
# SRC				+= $(addprefix parsing/, $(SUB_SRC))

SUB_SRC			:= main.c \
					sety_hooks.c \
					test_hooks.c \
					mapy_hooks.c
SRC				+= $(addprefix nmap/, $(SUB_SRC))

SUB_SRC			:= mapy.c \
					sety_f.c \
					exey_f.c
SRC				+= $(addprefix mapy/, $(SUB_SRC))

SUB_SRC			:= prompty.c
SRC				+= $(addprefix prompty/, $(SUB_SRC))

SUB_SRC			:= buildy_ipv4_tcp.c \
					buildy_utils.c
SRC				+= $(addprefix buildy/, $(SUB_SRC))

SUB_SRC			:= recy_ipv4_tcp.c
SRC				+= $(addprefix recy/, $(SUB_SRC))

SUB_SRC			:= sendy_ipv4_tcp.c
SRC				+= $(addprefix sendy/, $(SUB_SRC))

SUB_SRC			:= cleany.c
SRC				+= $(addprefix cleany/, $(SUB_SRC))

OBJ				:= $(SRC:%.c=$(OBJ_DIR)/%.o)
PREP			:= $(SRCS:.c=$(OBJ_DIR)/%.i)
ASSS			:= $(SRCS:.c=$(OBJ_DIR)/%.s)
DEPS			:= $(SRCS:.c=$(OBJ_DIR)/%.d)

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_GREY	 		= \033[1;38m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m
B_BLUE 			= \033[1;34m
B_YELLOW 		= \033[1;33m
B_WHITE 		= \033[1;37m


# MAKEFILE
$(NAME): lib $(OBJ) $(PREP) $(ASSS)
	@printf "$(CL_LINE)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_NAMES) -o $@ -lpthread
	@echo "[1 / 1] - $(B_MAGENTA)$@"
	@echo "$(B_GREEN)Compilation done !$(NONE)"

lib:
	@make -C $(LIBFT_DIR)
# @make -C $(BUILD_DIR)
# @make -C $(CLEAN_DIR)
# @make -C $(MAPY_DIR)
# @make -C $(CLEAN_DIR)
# @make -C $(SEND_DIR)
# @make -C $(SETUP_DIR)
	
lib_clean:
	@make -C $(LIBFT_DIR) clean
# @make -C $(BUILD_DIR) clean
# @make -C $(CLEAN_DIR) clean
# @make -C $(MAPY_DIR) clean
# @make -C $(CLEAN_DIR) clean
# @make -C $(SEND_DIR) clean
# @make -C $(SETUP_DIR) clean
	
all: $(NAME)

clean: lib_clean
	@rm -Rf $(BUILD)
	@echo "$(B_GREY)$(BUILD)$(NONE): $(B_YELLOW)Delete$(NONE)"

fclean: clean
	@rm -Rf $(NAME)
	@rm -Rf $(LIB_NAMES)
	@echo "$(B_GREY)$(NAME)$(NONE): $(B_YELLOW)Delete$(NONE)"

norm:
	cppcheck --addon=misra/misra.json $(addprefix $(SRC_DIR)/, $(SRC)) $(INC_DIR)/*.h

re: fclean all

debug: CFLAGS += -DDEBUG -fsanitize=thread -g3
debug: re

.PHONY: all clean fclean re debug lib

$(BUILD):
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs object : $(B_CYAN)$< $(NONE)...\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 

$(ASM_DIR)/%.s:$(SRC_DIR)/%.c | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs asm : $(B_CYAN)$< $(NONE)...\r"
	$(CC) $(CFLAGS) $(OPTFLAGS) $(IFLAGS) -S -o $@ $^

$(PROC_DIR)/%.i:$(SRC_DIR)/%.c | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs preprocessed : $(B_CYAN)$< $(NONE)...\r"
	$(CC) $(CFLAGS) $(OPTFLAGS) $(IFLAGS) -E -o $@ $^
