# thread-safe-counter

## Project 2 : Mutex vs Semaphore
* tscounter.c : use mutex
* sem_counter.c : use semaphore

## How to use makefile
* make exe about Mutex : tscounter.c
'''
make
'''
=> then make tscounter.o and tscounter
* run exe about Mutex : tscounter
'''
make p_run
'''
=> then tscounter will run
*  make exe about semaphore : sem_counter.c
'''
make sema 
'''
=> then make sem_counter.o and sema
* run exe about semaphore : sema
'''
make s_run
'''
=> then sema will run
* init
'''
make clean
'''


## Performance Comparison Table
[!download](https://github.com/jongchank/thread-safe-counter/files/6582530/-.1.1.pdf)

Mutex is faster than Semaphore



