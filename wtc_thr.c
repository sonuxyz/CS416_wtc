#include "wtc.h"

/*
 * 		NUM_P IS NUMBER OF PROCESSES/THREADS
 *
 * 		SIZE_N IS NUMBER OF VERTICES
 */

void wtc_thr(char* filename) {
	struct timeval t1,t2;
	long ts, tms;
	int a, mult;
	pthread_t threadArray[num_p];
	pthread_mutex_init(&mutex, NULL);

	gettimeofday(&t1, NULL);

    initialize(filename);
    print_matrix();

    printf("\nAfter:\n");

    for (a = 0; a < num_p; a++) {
    	mult = size_n / num_p;

    	function_args my_args;
    	my_args.start = a*mult;
    	my_args.test = 2+a;
    	if(((a+1)*mult-1)> (size_n-1))
    	{
    		my_args.end = size_n-1;
    	}
    	else
    	{
    		my_args.end = (a+1)*mult-1;
    	}
    	//my_args.end = (a == num_p-1) ? (a+1)*mult : (a+1)*mult - 1;
    	//my_args.end = (a+1)*mult;

    	pthread_create(&threadArray[a], NULL, (void*) function, (void*) &my_args);
    	pthread_join(threadArray[a], NULL);
    }





    gettimeofday(&t2, NULL);

    pthread_mutex_destroy(&mutex);





    print_matrix();
    free(matrix);

    tms = t2.tv_usec - t1.tv_usec;
    ts = t2.tv_sec - t1.tv_sec;
    printf("The time taken is: %lu.%lu seconds \n", ts, tms);




}

void function(void *args) {
	function_args *my_args;
	my_args = (function_args *) args;
    int k, i, j;

    for (k = 0; k < size_n; k++) { //loop through row
        for (i = my_args->start; i <= my_args->end; i++) {
            if (matrix[(k*size_n) + i] == 1) { //if matrix[k][i] == 1

                for (j = 0; j < size_n; j++) { //treat i as new row and j as column
                	pthread_mutex_lock(&mutex);
                    if (matrix[(i*size_n) + j] == 1) { //if matrix[i][j] == 1
                        matrix[(k*size_n) + j] = 1; //my_args->test; //set matrix[k][j] == 1
                    }
                    pthread_mutex_unlock(&mutex);
                }

            }
        }
   }
    pthread_exit(0);
}
