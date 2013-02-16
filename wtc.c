/*
 * wtc.c
 *  The class with a main method.
 *  Creates n threads to find the transitive closure of a directed graph
 *  Outputs to stdout (the screen).
 *
 *  There are four ways it does this:
 *  1. Process-level concurrency
 *  2. Thread-level concurrency
 *  3. Process level concurrency (with queue)
 *  4. Thread-level concurrency (with queue)
 *
 *  Input example: wtc 2 input.in
 *  Would determine transitive closure of a graph represented in input.in with thread-level concurrency (no queues).
 *
 *  Created on: Feb 5, 2013
 *      Author: Jonas Schreiber
 */

#include "wtc.h"

void initialize(char* filename) {
    FILE *file;
    int r = 0, c = 0;

    file = fopen(filename, "r");
    if (file) {
        if (fscanf(file, "%d", &r) == 1) {
            num_p = r;
        }
        if (fscanf(file, "%d", &r) == 1) {
            size_n = r;
        }

        matrix = malloc (size_n * size_n * sizeof(int));
        memset(matrix, 0, size_n * size_n);

        while (fscanf(file, "%d %d", &r, &c) == 2) {
            matrix[(r-1) * size_n + (c-1)] = 1;
        }
    }
    fclose(file);
}

void print_matrix() {
    int a, b;
    for (a = 0; a < size_n; a++) {
        for (b = 0; b < size_n; b++) {
            printf("%d ", matrix[a * size_n + b]);
        }
        printf("\n");
    }
}




int main(int argc, char *argv[]) {



	//TESTING
	wtc_thr("/ilab/users/pbai/Desktop/inputx.in");

	return 0;











	//check number of arguments, that argv[0] is in range 1-4, and that argv[2] is a file that can be opened
	if (argc != 2)
	{
		printf("Usage: wtc [method to use, denoted by 1, 2, 3, or 4] [name of file containing graph]");
		exit(0);
	}

	int method = atoi(argv[0]);
	if (method < 1 || method > 4)
	{
		printf("argument 1 must be in the range of 1-4");
		exit(0);
	}

	if(fopen(argv[1], "r") == NULL)
	{
		printf("Error: could not find or open the file containing graph");
		exit(0);
	}

	if (method == 1)
		wtc_proc(argv[1]);
	if (method == 2)
		wtc_thr(argv[1]);
	if (method == 3)
		//wtc_btproc(argv[1]);
	if (method == 4)
		//wtc_btthr(argv[1]);


    return 0;
}

