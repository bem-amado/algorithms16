/***************************************************************************
*   This is an implementation of bogo sort or stupid sort algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition : In terms of algortihms bogo sort is one of the worst
*   searching algorithm you can implement, it consists of radom shuffle the
*   unsorted array until it becomes sorted...
*   Runnig time: O(n!)
*
 ***************************************************************************/

//#include <bits/pthreadtypes-arch.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
typedef enum { true , false} bool;

void bogoSort(int array[], int size);
bool isSorted(int array[], int size);
void shuffle (int array[], int size);
//void delay(int seconds);


int size;
time_t *seed;

int
main(void){
    //int myArray[] = {5,17,25,64,32,2,14,79,93,6,41,4};
    int myArray[] = {32,1,4,5,0};
    size = sizeof(myArray)/sizeof(int);

    printf("Unsorted array : [");
    for (int i = 0; i<size; i++){
        printf("%d ", myArray[i]);
    }
    printf("]\n");

    // calling the bogo sort function
    bogoSort(myArray,size);

    printf("Sorted array  : [");
    for (int i = 0; i< size; i++){
        printf("%d ", myArray[i]);
    }
    printf("]\n");

    return 0;


}

/*
 *  Implementation of bogo sort
 */

void
bogoSort (int array[], int size){
    while(isSorted(array,size) != true){
        shuffle(array,size);
        usleep(500);
    }

}


/*
 * This function use the system current time to generate
 * a random number used to shuffle the array
 */

void
shuffle (int array[], int size){

    int tmp,j;
    srand(time(seed));
    for (int i = 0; i< size; i++){

        j = rand() % (size);
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

}
/*
 *  Verify if the array is sorted or not
 *  it returns true if the array is sorted or false if not
 */
bool
isSorted(int array[], int size){
    for(int i = 0; i < size-1 ; i++){
         if(array[i] >= array[i+1]){
            return false;
        }
    }

    return true;
}



//gcc (or clang) -o bogo bogo_sort.c
// time ./bogo
//output : [0 1 4 5 32 ]

//real    1m6.595s
//user    0m0.672s
//sys     0m1.008s

/*======================*/
// With an array of size 11 the algorithm becomes more insuffincient
//  real    211m51.320s
//  user    3m31.567s
//  sys     6m15.100s
