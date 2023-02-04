/***************************************************************************
*   This is an implementation of buble sort  algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition : In terms of algortihms bogo sort is one of the worst
*   searching algorithm you can implement, it consists of radom shuffle the
*   unsorted array until it becomes sorted...
*   Runnig time: O(nlogn)
*
*****************************************************************************/


#include <stdio.h>

void blubleSort(int array[], int size);
void swap (int*, int*);

int size;
int
main(void){

    int myArray [] = {92,1,25,44,2,97,4,-5,0,-2,-1,7,10};
    size = sizeof(myArray)/sizeof(int);
    printf("Input array => [");
    for (int i = 0; i < size; i++){
        printf("%d ", myArray[i]);

    }
    printf("]\n");

    blubleSort(myArray,size);

     printf("Output array => [");
    for (int i = 0; i < size; i++){
        printf("%d ", myArray[i]);

    }
    printf("]\n");


}

void
blubleSort(int array[], int size){

    for (int i = 0; i < size-1; i++ ){
        for(int j = 0; j < size-i-1; j++){
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
}

void
swap(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}





