CC = gcc


MODULES = ./buildy\
	 ./cleany	\
	 ./mappy	\
	 ./parsing\
	 ./proty	\
	 ./recy		\
	 ./sendy	\
	 ./setupy	\
	 ./nmap \
	 ./libft/inc \


INCFLAGS = $(foreach D,$(MODULES), -I$(D))

CFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2
DEPFLAGS = -MP -MD
BINARY = ft_nmap
SRCS = 	./setupy/setupy.c \
./nmap/main.c \
./setupy/setupy_ipv6_tcp.c \
./setupy/setupy_ipv4_tcp.c \
./setupy/setupy_ipv4_udp.c \
./setupy/setupy_ipv6_udp.c \
./cleany/cleany.c \
./mappy/mappy.c \
./mappy/sety.c \
./recy/recy_ipv6_udp.c \
./recy/recy_ipv4_tcp.c \
./recy/recy_ipv4_udp.c \
./recy/recy_ipv6_tcp.c \
./parsing/ft_isnumber.c \
./parsing/parse_scan.c \
./parsing/parse_ip.c \
./parsing/parser.c \
./parsing/parse_speedup.c \
./parsing/parse_ports.c \
./prompty/prompty.c \
./sendy/sendy_ipv6_tcp.c \
./sendy/sendy_ipv6_udp.c \
./sendy/sendy_ipv4_tcp.c \
./sendy/sendy_ipv4_udp.c \
./sendy/sendy.c \
./buildy/buildy_ipv4_tcp.c \
./buildy/buildy_ipv6_tcp.c \
./buildy/buildy_utils.c \
./buildy/buildy_ipv6_udp.c \
./buildy/buildy_ipv4_udp.c \
./buildy/buildy.c \
./parsing/error.c  \
 
#./sety/sety.c 

ASSS = $(SRCS:.c=.s)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
#DEPS = $(pathsubst %.c,%.d,$(SRCS))

all : ./Makefile $(BINARY) 

$(BINARY): $(ASSS) $(OBJS) 
	$(CC) -o $@ $(OBJS) ./libft/libft.a


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
