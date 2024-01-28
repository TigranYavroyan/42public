STATIC = libft.a
DYNAMIC = libft.so
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
SRC = ./src/
EXEC = a.out
ROOT = ./


FILES = $(wildcard $(ROOT)*.c)
OBJS = $(ROOT)*.o

.PHONY:  all clean fclean re so

all: $(STATIC)

$(STATIC) : $(OBJS)
	ar -rcs $(STATIC) $(OBJS)

$(OBJS) : $(FILES)
	$(CC) $(CFLAGS) $(FILES)

so: $(DYNAMIC)

$(DYNAMIC) : $(OBJS)

	$(CC) -fPIC $(CFLAGS) $(FILES)
	gcc -shared -o $(DYNAMIC) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(STATIC) $(DYNAMIC) $(EXEC) ./main/*.so

re: fclean all
