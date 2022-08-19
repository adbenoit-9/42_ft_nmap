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

OBJ_NAME	=	$(CHAR:.c=.o)
OBJ_NAME	+=	$(GNL:.c=.o)
OBJ_NAME	+=	$(LST:.c=.o)
OBJ_NAME	+=	$(MEM:.c=.o)
OBJ_NAME	+=	$(NBR:.c=.o)
OBJ_NAME	+=	$(STR:.c=.o)
OBJ_NAME	+=	$(TAB:.c=.o)
PATH_nmap     += nmap   

OBJ			=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))
ASS			=	$(addprefix $(ASS_DIR),$(OBJ_NAME))

$(OBJ_PATH)%.o:	$(CHAR_PATH)%.c $(HEADER)


INCFLAGS = $(foreach D,$(MODULES), -I$(D))

ARCHIVE=

CFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2
DEPFLAGS = -MP -MD
SRCS = buildy.c  buildy_ipv4_tcp.c  buildy_ipv4_udp.c	buildy_ipv6_tcp.c  buildy_ipv6_udp.c  buildy_utils.c
SRCS += 

OBJ_DIR 		:= obj
INC_DIR 		:= incs
#ASS_DIR			:= 
 
ASSS = $(SRCS:.c=.s)
OBJS:= $(SRC:%.c=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:.c=.d)
SPEC=
#DEPS = $(pathsubst %.c,%.d,$(SRCS))

all : ./Makefile $(BINARY) 

$(BINARY): $(ASSS) $(OBJS)  $(SPEC)
	ar rc $(OBJS)


%.o:%.c
	$(CC) $(CFLAGS)  $(INCFLAGS) $(DEPFLAGS) -c -o $@ $^ 

%.s:%.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -S -o $@ $^ 


clean :
	rm -rf $(BINARY)
	rm -rf $(OBJS)
	rm -rf $(DEPS)
	rm -rf $(ASSS)

release: clean
	tar zcvf release.tgz *
gstats:
	git status

gdiff:
	git diff --color --stat

spec: $(OBJS)
	$(CC) -o $@ $(OBJS) -fdump-ada-spec
	mkdir -f ads
	mv *.ads ads
	

re: clean all



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
