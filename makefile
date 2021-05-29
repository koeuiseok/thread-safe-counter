CC = gcc
CFLAGS = -Wall -c -g -pthread
LDFLAGS = -Wall -g -pthread

OBJS = tscounter.o
TARGET = tscounter

$(TARGET): $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^ 

tscounter.o: tscounter.c
	$(CC) $(CFLAGS) -o $@ $<   

sema: sem_counter.o
	$(CC) $(LDFLAGS) -o $@ $^

sem_counter.o: sem_counter.c
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -f *.o
	rm -f $(TARGET)

p_run: tscounter
	./tscounter 100000

s_run: sema
	./sema 100000
