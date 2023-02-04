/***************************************************************************
*   This is an implementation of selection sort algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition : Selection sort is a simple sorting algorithm.
*   Runnig time: O(n*n)
*
*****************************************************************************/

#include <stdio.h>

void selectionSort(int array[], int size);
void printArray(int array[], int size);

int size;

int
main(void){

    int myArray[] = {56,64,11,26,-4,-2,1,14,2,17,-1,-3,0,44,10};
    size = sizeof(myArray) /sizeof(int);
    printf("Unsorted array => [ ");
    printArray(myArray, size);

    //call selection sort
    selectionSort(myArray, (size));
    printf("Sorted array => [ ");
    printArray(myArray,size);


    return 0;
}

/*
 * implementation of selection sort
 */
void selectionSort(int array[], int size){

    int mini_index;
    int temp;
    for (int i = 0; i < size; i++){

        //select the begin of the array as the mini value
        mini_index = i;
        //find new mini value in the array
        for(int j = i+1; j < size ; j++){
            if(array[j] < array[mini_index]){
                mini_index = j;
            }
        }

        //swap the new minimum with the begin of the array
        if (i != mini_index){
            temp = array[i];
            array[i] = array[mini_index];
            array[mini_index] = temp;
        }

    }
}


/*
 * This function is a utility to help us print array before and after
 * merge sort
 */
void printArray(int array[], int size){

    for (int i = 0; i < size ; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");

}



// gcc -o select selection_sort.c
// time ./select
/*out put :
Unsorted array => [ 56 64 11 26 -4 -2 1 14 2 17 -1 -3 0 44 10 ]
Sorted array => [ -4 -3 -2 -1 0 1 2 10 11 14 17 26 44 56 64 ]

real    0m0.002s
user    0m0.002s
sys     0m0.000s
*/


