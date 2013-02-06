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


