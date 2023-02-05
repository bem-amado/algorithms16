/***************************************************************************
*   This is an implementation of merge sort algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition : Merge sort is a divide and conquer algorithm, in wich
*   we divide the unsorted array in small sub-arrays unsing recursion and then
*   we combine/merge the sub-arrays at the end
*   Runnig time: O(n*logn)
*
*****************************************************************************/

#include <stdio.h>

void mergeSort(int array [], int left, int rigth);
void merge(int array[],int left,int midle, int rigth);
void printArray(int array[], int size);

int size ;

int
main(void){

    int myArray [] = {43,11,26,2,7,1,-1,49,0,-2,53,3};
    size = sizeof(myArray) / sizeof(int);


    printf("Unsorted array => [ ");
    printArray(myArray,size);

    //call merge sort
    mergeSort(myArray,0,(size-1));

    //print sorted array
    printf("Sorted array => [ ");
    printArray(myArray,size);

    return 0;
}


/*
 *This function  is the implementation of merge sort using recursion
 */
void mergeSort(int array [], int left, int rigth){

    int midle;
    //base case to stop recursion
    if(left > rigth){
        //array is sorted
        return;
    }

    //recursive case
    if(left < rigth){
        //find the midle point
        midle  = (left + rigth) /2;
        mergeSort(array, left, midle);
        mergeSort(array, (midle+1), rigth);
        merge(array, left, midle, rigth);

    }

}

/*
 *We create two sub-arrays inside this functions and we compare elements
 *from the two sub-arrays then we merge the result in a new sorted array
 */
void merge(int array[],int left,int midle, int rigth) {

    //n1 and n2 are the sizes for new sub-arrays
    int n1,n2;
    n1 = midle  - left + 1;
    n2 = rigth - midle;

    //create new sub-arrays
    int T1[n1];
    int T2[n2];

    //copy elements from the original array to sub-arrays
    for(int i = 0; i < n1; i++)
        T1[i] = array[left + i];
    for(int j = 0; j < n2; j++)
        T2[j] = array[midle + 1 + j];

    //3 pointers for 3 arrays
    int i,j,k;
    i = 0; //for T1
    j = 0; // for T2
    k = left; //for sorting array

    //while we still having elements in one of the two sub-arrays, compare and
    //copy
    while( i < n1 && j < n2){

        if(T1[i] <= T2[j]){
            array[k] = T1[i];
            i++;
        }else{
            array[k] = T2[j];
            j++;
        }
        k++;
    }

    //copy remaining elements
    while (i < n1){
        array[k] = T1[i];
        i++;
        k++;
    }

    while (j < n2){
        array[k] = T2[j];
        j++;
        k++;
    }

}

/*
 * This function is an utility to help us print array before and after
 * merge sort
 */
void printArray(int array[], int size){

    for (int i = 0; i < size ; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");

}


//To compile use gcc or clang : gcc -o merge merge_sort.c
//To execute : time ./merge
/*output :
Unsorted array => [ 43 11 26 2 7 1 -1 49 0 -2 53 3 ]
Sorted array => [ -2 -1 0 1 2 3 7 11 26 43 49 53 ]

real    0m0.002s
user    0m0.002s
sys     0m0.000s
*/
