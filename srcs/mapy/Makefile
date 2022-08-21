
NAME=bin
SRCS= mapy.c \
		test/main.c \
		test/test.c \
		mapy_f.c \
		sety_f.c \
		exey_f.c

#OPTFLAGS=-O3
#OPTFLAGS=-fsanitize=thread -g3
OPTFLAGS= -g3

OBJS = $(SRCS:.c=.o)
PREP = $(SRCS:.c=.i)

all: $(NAME)

	

$(NAME):  $(LIBFT) $(OBJS)  
	$(CC) -o $@ $(OBJS) 

%.i:%.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -E -o $@ $^  

%.o:%.c 
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCFLAGS) -c $^ -o $@ -save-temps=obj

#	gcc -c $(SRCS) -save-temps=obj
#	gcc -c $(SRCS) -save-temps=obj

clean:
	rm  $(OBJS) $(ASSS)

re: clean all
