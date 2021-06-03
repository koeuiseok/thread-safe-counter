# thread-safe-counter

## Project 2 : Mutex vs Semaphore
* tscounter.c : use mutex
* sem_counter.c : use semaphore

## How to use makefile

* make exe about Mutex : tscounter.c
```
make
```
=> then make tscounter.o and tscounter

* run exe about Mutex : tscounter
```
make p_run
```
=> then tscounter will run

*  make exe about semaphore : sem_counter.c
```
make sema 
```
=> then make sem_counter.o and sema

* run exe about semaphore : sema
```
make s_run
```
=> then sema will run

* init
```
make clean
```


## Performance Comparison Table
![20161890](https://user-images.githubusercontent.com/62655939/120437652-4e023400-c3bb-11eb-928d-c4f65816a751.png)

Mutex is faster than Semaphore



