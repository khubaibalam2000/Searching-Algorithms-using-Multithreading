#include <pthread.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <omp.h>

struct Args{
	int *arr;
    int key;
    int start;
    int end;
    int choice;
    int keyFound;
};

    float timespent[15];
    float arraySize[8] = {16,256,4096,65536,1048576,16777216,67108864,100000000};
    
    float LST1PT[8], LST1OMP[8];
    float LST2PT[8], LST2OMP[8];
    float LST4PT[8], LST4OMP[8];
    
    float BST1PT[8], BST1OMP[8];
    float BST2PT[8], BST2OMP[8];
    float BST4PT[8], BST4OMP[8];
    
	float TST1PT[8], TST1OMP[8];
    float TST2PT[8], TST2OMP[8];
    float TST4PT[8], TST4OMP[8];

	float JST1PT[8], JST1OMP[8];
    float JST2PT[8], JST2OMP[8];
    float JST4PT[8], JST4OMP[8];
    
   	float IST1PT[8], IST1OMP[8];
    float IST2PT[8], IST2OMP[8];
    float IST4PT[8], IST4OMP[8];

#define INT2VOIDP(i) (void*)(uintptr_t)(i)

void* LinearSearchUsingPthreads(void *receivedArgs){
    struct Args *struct_ptr = (struct Args*) receivedArgs;
    int j;
   
    for(j=struct_ptr->start; j<struct_ptr->end; j++){
        if(struct_ptr->key == struct_ptr->arr[j]){
            struct_ptr->keyFound = j;
            if(struct_ptr->choice == 2){
                pthread_exit(NULL);
            } else {
                break;
            }
        }
    }
    if(struct_ptr->choice == 2) pthread_exit(NULL);
    return 0;
}

void* BinarySearchUsingPthreads(void *receivedArgs){
    struct Args *struct_ptr = (struct Args*) receivedArgs;
    if(struct_ptr->choice == 2 && struct_ptr->end < struct_ptr->key){
        pthread_exit(NULL);
    }
    if (struct_ptr->end >= struct_ptr->start) {
        int mid = struct_ptr->start + (struct_ptr->end - struct_ptr->start) / 2;

        if (struct_ptr->arr[mid] == struct_ptr->key){
            struct_ptr->keyFound = mid;
            if(struct_ptr->choice == 2){
                pthread_exit(NULL);
            } else {
                void* val = INT2VOIDP(mid);
                return val;
            }
        }
        if (struct_ptr->arr[mid] > struct_ptr->key){
            struct_ptr->end = mid - 1;
            return BinarySearchUsingPthreads(receivedArgs);
        }
        else{
            struct_ptr->start = mid + 1;
            return BinarySearchUsingPthreads(receivedArgs);
        }
    }
    return 0;
}

void* TernarySearchUsingPthreads(void *receivedArgs){
    struct Args *struct_ptr = (struct Args*) receivedArgs;
    if(struct_ptr->choice == 2 && struct_ptr->end < struct_ptr->key) pthread_exit(NULL);
    if (struct_ptr->end >= struct_ptr->start) {

        int mid1 = struct_ptr->start + (struct_ptr->end - struct_ptr->start) / 3;
        int mid2 = struct_ptr->end - (struct_ptr->end - struct_ptr->start) / 3;

        if (struct_ptr->arr[mid1] == struct_ptr->key){
            struct_ptr->keyFound = mid1;
            if(struct_ptr->choice == 2){
                pthread_exit(NULL);
            } else {
                void* val = INT2VOIDP(mid1);
                return val;
            }
        }

        if (struct_ptr->arr[mid2] == struct_ptr->key){
            struct_ptr->keyFound = mid2;
            if(struct_ptr->choice == 2){
                pthread_exit(NULL);
            } else {
                void* val = INT2VOIDP(mid2);
                return val;
            }
        }

        if (struct_ptr->arr[mid1] > struct_ptr->key){
            struct_ptr->end = mid1 - 1;
            return TernarySearchUsingPthreads(receivedArgs);
        }
        else if (struct_ptr->arr[mid2] < struct_ptr->key){
            struct_ptr->start = mid2 + 1;
            return TernarySearchUsingPthreads(receivedArgs);
        }
        else{
            struct_ptr->start = mid1 + 1;
            struct_ptr->end = mid2 - 1;
            return TernarySearchUsingPthreads(receivedArgs);
        }
    }
    return 0;
}
