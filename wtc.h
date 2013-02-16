#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include <semaphore.h>
#include <pthread.h>
//#include <sys/wait.h>
//#include <sys/mman.h>

int num_p; //the number of processes or threads
int size_n; //size n of nxn matrix
int* matrix; //2D matrix is represented by 1D array

struct functionArgs
{
	int start;
	int end;
	int test;
}
typedef function_args;

pthread_mutex_t mutex;


/* Warshall's Algorithm */
void function(void *args);

/* Reads p and n from the file, and initializes the input matrix */
void initialize(char* filename);

void print_matrix();

void wtc_proc();
void wtc_thr(char* filename);
