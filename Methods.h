#include "SearchingAlgorithms.h"
#include <omp.h>
#include <time.h>

void SerialProgramming(int arr[], int key, int n, int choice2){
    int choice;
    struct Args threadArgs;
    threadArgs.key = key;
    threadArgs.arr=(int *)malloc(sizeof(int)*n);
    memcpy(threadArgs.arr, arr, n*sizeof(int));
    threadArgs.choice = choice2;
    threadArgs.keyFound = -1;
    choice = 1; int i = 1;
    for (i=1; i<=3; i++){
	
    switch(i){
        case 1:
        {
        	threadArgs.start = 0;
		    threadArgs.end = n;
            clock_t begin = clock();
            LinearSearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[0] = time_spent;
        }
        case 2:
        {
        	threadArgs.start = 0;
    		threadArgs.end = n;
            clock_t begin = clock();
            BinarySearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[1] = time_spent;
        }
        case 3:
        {
        	threadArgs.start = 0;
		    threadArgs.end = n;
            clock_t begin = clock();
            TernarySearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[2] = time_spent;
        }
    	}
    }
}


void* LinearSearchUsingOMP(void *receivedArgs, int n){
	struct Args *struct_ptr = (struct Args*) receivedArgs;
	int j;
	struct_ptr->start=0;
	struct_ptr->end=n;
	clock_t begin = clock();
	#pragma omp parallel for
	    for(j=struct_ptr->start; j<struct_ptr->end; j++){
	        if(struct_ptr->key == struct_ptr->arr[j]){
	            struct_ptr->keyFound = j;
	        }
	    }
	clock_t end = clock();
	double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
	timespent[10] = time_spent;
	return 0;
}

void OMPProg(int arr[], int key, int n, int choice){
    int tid, numt;
    
    struct Args threadArgs;
    threadArgs.arr=(int *)malloc(sizeof(int)*n);
    memcpy(threadArgs.arr, arr, n*sizeof(int));
    threadArgs.key = key;
    threadArgs.choice = choice;
    threadArgs.keyFound = -1;
    int choice2=2;
    int from, to;
    int i=0,j=0,noOfThreads=0;
	LinearSearchUsingOMP((void*)&threadArgs, n);
	for(j=0; j<3; j++){
		noOfThreads=(j==0 ? 1 : j==1 ? 2 : j==2 ? 4 : 4);
	    for(i=2; i<=4; i++){
	    clock_t begin = clock();
	   #pragma omp parallel default(shared) private(tid) num_threads(noOfThreads)
	   {
	       tid = omp_get_thread_num();
	       numt = omp_get_num_threads();
	
	       threadArgs.start = (n/numt) * tid;
	       threadArgs.end = (n/numt) * (tid + 1);
	       switch(choice2){
	           case 2:
	           {
	               BinarySearchUsingPthreads((void*)&threadArgs);
	               break;
	           }
	           case 3:
	           {
	               TernarySearchUsingPthreads((void*)&threadArgs);
	               break;
	           }
	           default:
	           {
	               break;
	           }
	       }
	   }
		   choice2++;
		}
		choice2=2;
	}
	if(threadArgs.keyFound != -1){
		printf("Key Exists at %d", threadArgs.keyFound);
	} else {
		printf("-1");
	}
}
