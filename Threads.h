
#ifndef EX2OS_THREAD_H
#define EX2OS_THREAD_H

#include <stdio.h>
#include <setjmp.h>
//#include <stdlib.h>
#include <signal.h> //?
#include <unistd.h>

// Defines for this class
#define RUNNING 0
#define READY 1
#define BLOCKED 2
#define TERMINATED 3

class Thread
{
private:
    //Thread(void (*)(void), f, int tid, int priority, int stack_size);

    int __thread_id ;           //thread's ID number
    char *__thread_stack_p;    //thread's stack pointer
    int __thread_cs;            //thread's current state
    int __thread_priority;      //thread's priority
    int __num_of_quantum = 0;  //thread's quantum
    void (*f)(void);
public:
    Thread(void (*f)(void), int tid, int priority);
    ~Thread();
    int getId ();
    int getState();
    int getQuantum();
    int getPriority();
    void setState(int next_state);
    void setPriority(int new_priority);
    void incrQuantum();
    sigjmp_buf env;
};

#endif //EX2OS_THREAD_H
