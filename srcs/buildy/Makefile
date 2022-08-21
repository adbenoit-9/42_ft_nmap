CC = gcc
DEPS =   ../buildy\
	 		../cleany	\
	 		../mappy	\
	 		../parsing\
	 		../proty	\
	 		../recy		\
	 		../sendy	\
	 		../setupy	\
	 		../nmap \

MODULES	:= ../mapy

OBJ			=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))
ASS			=	$(addprefix $(ASS_DIR),$(OBJ_NAME))

$(OBJ_PATH)%.o:	$(CHAR_PATH)%.c $(HEADER)


INCFLAGS = $(foreach D,$(MODULES), -I$(D))

ARCHIVE=

CFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2
DEPFLAGS = -MP -MD

SRC = buildy_ipv4_tcp.c\
		buildy_utils.c
# buildy_ipv4_udp.c\
# buildy_ipv6_tcp.c\
# buildy_ipv6_udp.c

BUILD 		:= .build
OBJ_DIR 	:= $(BUILD)/obj
ASM_DIR 	:= $(BUILD)/asm
# INC_DIR 		:= incs
#ASS_DIR			:= 

OBJ			:= $(SRC:%.c=$(OBJ_DIR)/%.o)
ASM			:= $(SRC:%.c=$(ASM_DIR)/%.o)
# DEPS		:= $(SRC:.c=.d)
# SPEC=
#DEPS = $(pathsubst %.c,%.d,$(SRCS))

NAME	:= buildy.a

all : $(NAME) 

$(NAME): $(OBJ) $(ASM)
	@ar rc $(NAME) $(OBJ)
	@printf "\n"
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"

$(BUILD):
	@mkdir $@ $(OBJ_DIR)

$(OBJ_DIR)/%.o:%.c | $(BUILD)
	@$(CC) $(CFLAGS)  $(INCFLAGS) $(DEPFLAGS) -c -o $@ $^ 

$(OBJ_DIR)/%.s:%.c | $(BUILD)
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -S -o $@ $^ 


clean :
	@rm -Rf $(BUILD)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean: clean
	@rm -Rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: deleted\033[0m"

release: clean
	tar zcvf release.tgz *
gstats:
	git status

gdiff:
	git diff --color --stat

spec: $(OBJ)
	$(CC) -o $@ $(OBJ) -fdump-ada-spec
	mkdir -f ads
	mv *.ads ads
	
re: fclean all

.PHONY: all clean fclean re debug

debug:
	@echo $(OBJ_DIR)/%.o



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
