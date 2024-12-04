EXEC = i2c_example
SRC = main.c
CFLAGS = -Wall -Wextra -O2
 
all: $(EXEC)
 
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)
 
clean:
	rm -rf $(EXEC) *.o