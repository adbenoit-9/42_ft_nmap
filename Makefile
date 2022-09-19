# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 16:29:13 by adbenoit          #+#    #+#              #
#    Updated: 2022/09/19 16:34:33 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= ft_nmap

# COMPILATION

CC		= gcc-10
CFLAGS 	= -Wall -Wextra -Werror -g3 -fsanitize=thread
OPTFLAGS = -O2  
DEPFLAGS = -MP -MD
	 	 
IFLAGS 	= $(foreach D,$(INC_DIR), -I$(D))

UNAME	:= $(shell uname)
ifeq ($(UNAME), Darwin)
	CFLAGS += -DMAC
endif

SRC_DIR 		:= srcs

## LIBRARIES
BUILD_DIR		:= $(SRC_DIR)/buildy
CLEAN_DIR		:= $(SRC_DIR)/cleany
SEND_DIR		:= $(SRC_DIR)/sendy
SETUP_DIR		:= $(SRC_DIR)/setupy
REC_DIR			:= $(SRC_DIR)/recy
MAP_DIR			:= $(SRC_DIR)/mapy
PARS_DIR		:= $(SRC_DIR)/parsy
REPORT_DIR		:= $(SRC_DIR)/reporty
ANAL_DIR		:= $(SRC_DIR)/analysy
LIBFT_DIR		:= $(SRC_DIR)/libft

LIBFT_NAME		:= $(LIBFT_DIR)/libft.a
LIB_NAMES		:= $(BUILD_DIR)/buildy.a\
					$(CLEAN_DIR)/cleany.a\
					$(REC_DIR)/recy.a\
					$(SEND_DIR)/sendy.a\
					$(PARS_DIR)/parsy.a\
					$(LIBFT_DIR)/libft.a\
					$(SETUP_DIR)/setupy.a\
					$(REPORT_DIR)/reporty.a\
					$(ANAL_DIR)/analysy.a

# FILES
BUILD 			:= .build

INC_SUB_DIR		:= buildy\
					cleany\
					libft/inc \
					mapy\
					nmap/incs\
					parsy\
					prompty\
					proty\
					recy\
					sendy\
					setupy\
					reporty\
					analysy

INC_DIR 		:= $(addprefix $(SRC_DIR)/, $(INC_SUB_DIR))

SUB_DIR			:= buildy\
					cleany\
					mapy\
					nmap\
					parsy\
					prompty\
					recy\
					reporty\
					sendy\
					setupy\
					analysy
					
DIRS			:= $(addprefix $(BUILD)/, $(SUB_DIR))

SRC				:=
SUB_SRC			:= main.c \
					nmap_sety_hooks.c \
					nmap_print.c \
					nmap_exey_hooks.c \
					nmap_iter_hooks.c \
					nmap_scany.c \
					nmap_signal.c \
					nmap_timeout.c \
					nmap.c
SRC				+= $(addprefix nmap/, $(SUB_SRC))
SUB_SRC			:= analysy_synscan.c \
					analysy_udpscan.c \
					analysy_ackscan.c \
					analysy_fnxscan.c \
					analysy_utils.c
SRC				+= $(addprefix analysy/, $(SUB_SRC))
SUB_SRC			:= buildy_ipv4_tcp.c \
					buildy_utils.c \
					buildy_ipv4_udp.c \
					buildy_ipv6_tcp.c \
					buildy_ipv6_udp.c \
					buildy_checksum.c
SRC				+= $(addprefix buildy/, $(SUB_SRC))
SUB_SRC			:= cleany.c
SRC				+= $(addprefix cleany/, $(SUB_SRC))
SUB_SRC			:= parsy.c \
					parsy_ip.c \
					parsy_scan.c \
					parsy_ports.c \
					parsy_speedup.c \
					parsy_verbose.c \
					parsy_error.c \
					parsy_clean.c \
					ft_isnumber.c
SRC				+= $(addprefix parsy/, $(SUB_SRC))
SUB_SRC			:= recy_ipv4.c \
					recy_ipv6.c \
					recy_utils.c
SRC				+= $(addprefix recy/, $(SUB_SRC))
SUB_SRC			:= reporty_config.c \
					reporty_final.c \
					reporty_blk.c
SRC				+= $(addprefix reporty/, $(SUB_SRC))
SUB_SRC			:= sendy_tcp.c \
					sendy_udp.c
SRC				+= $(addprefix sendy/, $(SUB_SRC))
SUB_SRC			:= setupy_ipv4_tcp.c \
					setupy_ipv4_udp.c \
					setupy_ipv6_tcp.c \
					setupy_ipv6_udp.c
SRC				+= $(addprefix setupy/, $(SUB_SRC))
SUB_SRC			:= mapy.c \
					sety_f.c \
					exey_f.c \
					blky.c
SRC				+= $(addprefix mapy/, $(SUB_SRC))
SUB_SRC			:= prompty.c
SRC				+= $(addprefix prompty/, $(SUB_SRC))

OBJ				:= $(SRC:%.c=$(BUILD)/%.o)
PREP			:= $(SRC:%.c=$(BUILD)/%.i)
#ASSS			:= $(SRC:%.c=$(BUILD)/%.s)
DEPS			:= $(SRC:%.c=$(BUILD)/%.d)

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
$(NAME): $(LIBFT_NAME) $(OBJ) $(PREP) 
	@printf "$(CL_LINE)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_NAME) -o $@ -lpthread -lpcap
	@echo "[1 / 1] - $(B_MAGENTA)$@"
	@echo "$(B_GREEN)Compilation done !$(NONE)"

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

lib_debug:
	@make -C $(LIBFT_DIR) debug
	@make -C $(BUILD_DIR) debug
	@make -C $(CLEAN_DIR) debug
	@make -C $(REC_DIR) debug
	@make -C $(SEND_DIR) debug
	@make -C $(PARS_DIR) debug
	@make -C $(SETUP_DIR) debug
	@make -C $(REPORT_DIR) debug
	@make -C $(ANAL_DIR) debug

lib:
	@make -C $(LIBFT_DIR)
	@make -C $(BUILD_DIR)
	@make -C $(CLEAN_DIR)
	@make -C $(REC_DIR)
	@make -C $(SEND_DIR)
	@make -C $(PARS_DIR)
	@make -C $(SETUP_DIR)
	@make -C $(REPORT_DIR)
	@make -C $(ANAL_DIR)
	
lib_clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(BUILD_DIR) clean
	@make -C $(CLEAN_DIR) clean
	@make -C $(REC_DIR) clean
	@make -C $(SEND_DIR) clean
	@make -C $(SETUP_DIR) clean
	@make -C $(PARS_DIR) clean
	@make -C $(REPORT_DIR) clean
	@make -C $(ANAL_DIR) clean
	
all: $(NAME)

clean:
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

$(BUILD):
	@mkdir $@ $(DIRS)

$(BUILD)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs object : $(B_CYAN)$< $(NONE)...\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 

$(BUILD)/%.s:$(SRC_DIR)/%.c | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs asm : $(B_CYAN)$< $(NONE)...\r"
	@$(CC) $(CFLAGS) $(OPTFLAGS) $(IFLAGS) -S -o $@ $^

$(BUILD)/%.i:$(SRC_DIR)/%.c | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs preprocessed : $(B_CYAN)$< $(NONE)...\r"
	@$(CC) $(CFLAGS) $(OPTFLAGS) $(IFLAGS) -E -o $@ $^

.PHONY: all clean fclean re debug lib lib_clean lib_debug norm
