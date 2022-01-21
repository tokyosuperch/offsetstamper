CC=gcc
OBJS=gpioin.c
LIBS=-lpthread -lpigpio
PROGRAM=gpioin.elf

all: $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)
