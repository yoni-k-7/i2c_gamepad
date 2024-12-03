EXEC = i2c_example
SRC = main.c
CFLAGS = -Wall -Wextra -O2
CC = gcc
 
all: $(EXEC)
 
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)
 
clean:
	rm -rf $(EXEC) *.o