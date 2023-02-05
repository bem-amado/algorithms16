/***************************************************************************
*   This is an implementation of insertion sort  algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition :In insertion sort we divide the array in two parts and we
*   consider the left side as sorted and the rigth side as unsorted then
*   we make space for the element that we want to insert
*   Runnig time: O(n*n)
*
*****************************************************************************/
#include <stdio.h>


void insertionSort(int array[], int size);
void printArray(int array[], int size);

int size;

int
main(void){

    int myArray [] = {6, 5, 3, 1, 8, 7, 2, 4};
    //the size of the Array
    size = sizeof(myArray)/sizeof(int);

    printf("Unsorted array => [ ");
    printArray(myArray,size);
    //call insertion sort
    insertionSort(myArray, size);
    printf("Sorted array => [ ");
    printArray(myArray,size);


    return 0;
}

/*
 * implementation of insertion sort
 */
void insertionSort(int array[], int size){

    int temp,j;
    j =0;
    for(int i = 1; i < size; i++ ){
        //put the element to insert in temp variable
        temp = array[i];
        j = i;
        while(j > 0 && array[j-1] > temp)
        {
            array[j] = array[j-1];
            j--;
        }
        //put the element to insert in it's place
        array[j] = temp;
    }
}



/*
 * This function is an utility to help us print array before and after
 * insertion sort
 */
void printArray(int array[], int size){

    for (int i = 0; i < size ; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");

}
