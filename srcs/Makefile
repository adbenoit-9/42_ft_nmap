CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2  
DEPFLAGS = -MP -MD

INCDIR = \
	 ./nmap 	\
	 ./buildy 	\
	 ./cleany	\
	 ./mapy	\
	 ./parsing	\
	 ./proty	\
	 ./recy		\
	 ./sendy	\
	 ./setupy	\
	 ./libft/inc \

INCFLAGS = $(foreach D,$(INCDIR), -I$(D))

BINARY = ft_nmap

SRCS = 	./nmap/main.c \
./nmap/sety_hooks.c \
./nmap/test_hooks.c \
./nmap/mapy_hooks.c \
./mapy/mapy.c \
./mapy/sety_f.c \
./mapy/exey_f.c \
./prompty/prompty.c \
./buildy/buildy_ipv4_tcp.c \
./buildy/buildy_utils.c \

#./cleany/cleany.c \
# ./parsing/error.c  \
# ./parsing/ft_isnumber.c \
# ./parsing/parse_scan.c \
# ./parsing/parse_ip.c \
# ./parsing/parser.c \
# ./parsing/parse_speedup.c \
# ./parsing/parse_ports.c \
# ./recy/recy_ipv6_udp.c \
# ./recy/recy_ipv4_tcp.c \
# ./recy/recy_ipv4_udp.c \
# ./recy/recy_ipv6_tcp.c \
# ./buildy/buildy_ipv6_tcp.c \
# ./buildy/buildy_ipv6_udp.c \
# ./buildy/buildy_ipv4_udp.c \
# ./sendy/sendy_ipv6_tcp.c \
# ./sendy/sendy_ipv6_udp.c \
# ./sendy/sendy_ipv4_tcp.c \
# ./sendy/sendy_ipv4_udp.c \
# ./setupy/setupy_ipv6_tcp.c \
# ./setupy/setupy_ipv4_tcp.c \
# ./setupy/setupy_ipv4_udp.c \
# ./setupy/setupy_ipv6_udp.c \
 
# $(warning Variables HERE: .VARIABLES)

PREP = $(SRCS:.c=.i)
ASSS = $(SRCS:.c=.s)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)


#DEPS = $(pathsubst %.c,%.d,$(SRCS))
	#$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -fdump-ada-spec -c $^ -o $@ -save-temps=obj

LIBFT=./libft/libft.a


all :  ./Makefile $(BINARY) $(PREP) $(ASSS) 

$(BINARY):  $(LIBFT) $(OBJS)  
	$(CC) -o $@ $(OBJS) ./libft/libft.a

%.o:%.c 
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -c $^ -o $@ -save-temps=obj


%.s:%.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -S -o $@ $^

%.i:%.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -E -o $@ $^  

$(LIBFT):
	make -C libft/


clean :
	make -C libft/ fclean
	rm -rf $(BINARY)
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean : clean
	rm -rf $(ASSS)
	rm -rf $(PREP)

release: clean
	tar zcvf release.tgz *
gstats:
	git status

gdiff:
	git diff --color --stat

re: fclean all



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
