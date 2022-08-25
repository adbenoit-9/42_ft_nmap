# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2022/08/25 18:50:15 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

INC			=	inc/
HEADER		=	$(INC)libft.h

SRC_PATH	=	src/
CHAR_PATH	=	$(SRC_PATH)char/
GNL_PATH	=	$(SRC_PATH)gnl/
LST_PATH	=	$(SRC_PATH)lst/
MEM_PATH	=	$(SRC_PATH)mem/
NBR_PATH	=	$(SRC_PATH)nbr/
STR_PATH	=	$(SRC_PATH)str/
TAB_PATH	=	$(SRC_PATH)tab/

MEM			=	ft_memset.c			ft_bzero.c			ft_memcpy.c \
				ft_memccpy.c		ft_memmove.c		ft_memchr.c \
				ft_memcmp.c			ft_calloc.c
				
STR			=	ft_strlen.c			ft_strchr.c			ft_strrchr.c \
				ft_strncmp.c		ft_strjoin.c		ft_strtrim.c \
				ft_strlcpy.c		ft_strlcat.c		ft_strnstr.c \
				ft_strdup.c			ft_substr.c			ft_strmapi.c\
				ft_split.c			ft_putstr_fd.c		ft_putendl_fd.c \
				ft_realloc.c		ft_strndup.c		ft_strncpy.c \
				ft_strcat.c			ft_strcpy.c			ft_strcmp.c

CHAR		=	ft_isalnum.c		ft_isalpha.c		ft_isascii.c \
				ft_isdigit.c		ft_isprint.c		ft_putchar_fd.c \
				ft_tolower.c		ft_toupper.c

NBR			=	ft_atoi.c			ft_itoa.c			ft_putnbr_fd.c		

LST			=	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c \
				ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c \
				ft_lstclear.c		ft_lstiter.c		ft_lstmap.c

TAB			=	ft_puttab_fd.c		ft_realloc_tab.c	ft_tabdup.c \
				ft_freetab.c		ft_tabsize.c

GNL			=	get_next_line.c
				

OBJ_PATH	=	obj/

OBJ_NAME	=	$(CHAR:.c=.o)
OBJ_NAME	+=	$(GNL:.c=.o)
OBJ_NAME	+=	$(LST:.c=.o)
OBJ_NAME	+=	$(MEM:.c=.o)
OBJ_NAME	+=	$(NBR:.c=.o)
OBJ_NAME	+=	$(STR:.c=.o)
OBJ_NAME	+=	$(TAB:.c=.o)

OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

all:	$(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"

$(OBJ_PATH)%.o:	$(CHAR_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(GNL_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(LST_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(MEM_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(NBR_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(STR_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(TAB_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME) 

FILE=norme_error.txt
ERROR= `cat $(FILE) | grep -B 1 "Error"`
norme:
	@printf "\033[33mLaunching ...\033[0m"
	@norminette */*/*c */*h > $(FILE)
	@printf "\rNorme of \033[33;1mLibft\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"
	@ echo "\r$(ERROR)"
	@rm $(FILE)

re: fclean all

.PHONY: all clean fclean re bonus

debug : re
