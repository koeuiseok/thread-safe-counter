CC = gcc
CFLAGS = -Wall -c -g -pthread
LDFLAGS = -Wall -g -pthread

OBJS = tscounter.o
TARGET = tscounter

$(TARGET): $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^ 

tscounter.o: tscounter.c
	$(CC) $(CFLAGS) -o $@ $<   


clean:
	rm -f *.o
	rm -f $(TARGET)

run: tscounter
	./tscounter 12121
