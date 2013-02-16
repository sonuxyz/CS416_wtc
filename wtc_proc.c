#include "wtc.h"

void wtc_proc(int start, int end) {
/*
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
