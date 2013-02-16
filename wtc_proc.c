/*
 * wtc_proc.c
 *
 *	This class determines transitive closure of a directed graph with process-level concurrency, without the use of a queue.
 *  Created on: Feb 5, 2013
 *      Author: Jonas Schreiber
 */

#include <stdlib.h>
#include "wtc.h"

void wtc_proc(char* filename) {
	return;
}

int **matrix;

int main(FILE *file) {
	FILE *graph = fopen(*file, "r");
	int numThreads;
	fscanf(graph, "%d", &numThreads);
	int numVertices;
	fscanf(graph, "%d", &numVertices);

	if(numThreads <= 0 || numThreads > numVertices)
	{
		printf("Error: The number of threads must be greater than 0 and less than the number of vertices.");
		exit(1);
	}

	matrix = malloc(numVertices * numVertices * sizeof(int));
	struct timeval start;
	gettimeofday(&start, NULL);

}

void worker(int numThreads, int numVertices, int beginRow, int rowsToPopulate, int pID) {

}

/*
void wtc_proc(int start, int end) {

	struct timeval t1,t2;
	long ts, tms;
	int a, mult, n;
	sem_t *sem;

	gettimeofday(&t1,NULL);

    initialize("/ilab/users/pbai/workspace/cs416/input1.txt");
    //print_matrix();

    pid_t childpids[num_p];
    n = num_p;

    printf("\nAfter:\n");




    for (a = 0; a < num_p; a++) {
    	if ((childpids[a] = fork()) < 0) {
    		printf("Failed to fork.\n");
    		exit(1);
    	}
    	else if (childpids[a] == 0) {

    		mult = size_n / num_p;
    		if((a*mult+mult) > size_n)
    		{
    			function(a*mult, (size_n-1));
    		}
    		else
    		{
    			function(a*mult, a*mult+mult-1);
    		}

    	}
    }

    int status;
    pid_t pid;
    while(n > 0) {
    	pid = wait(&status);
    	//printf("Child %d exited", (int)pid);
    	--n;
    }





    gettimeofday(&t2, NULL);
    printf("final\n");
    print_matrix();
    free(matrix);

    tms = t2.tv_usec - t1.tv_usec;
    ts = t2.tv_sec - t1.tv_sec;
    printf("The time taken is: %lu.%lu seconds \n", ts, tms);

*/
}
