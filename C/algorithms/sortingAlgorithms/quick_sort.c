/***************************************************************************
*   This is an implementation of quick sort algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition :
*   Runnig time: O(nlogn)
*
*****************************************************************************/

#include <stdio.h>


void quickSort(int array [], int left, int rigth);
void swap(int *position1, int *position2);
int partition (int array [],int left, int rigth);

int begin, end;

int
main (void){

    int myArray [] = {20,4,6,10,57,2,80,9,13,48,17};
    //int myArray[]={78,65,0,-5,2,-3,4,10,68,19,72,26,14,9,-20,11,32};
    begin = 0;
    end = sizeof(myArray)/sizeof(int);

    printf("Unsorted array => [");

    for(int i = 0; i < end; i++){
        printf("%d ", myArray[i]);
    }
    printf("]\n");

    //calling quick sort function
    quickSort(myArray,begin, (end-1));

    printf("Sorted array => [");

    for(int i = 0; i < end; i++){
        printf("%d ", myArray[i]);
    }
    printf("]\n");

    return 0;
}


void
quickSort(int array [],int left, int rigth) {

        int pivotIndex;

        if(left < rigth){

            pivotIndex = partition(array, left,rigth);
            quickSort(array,left,(pivotIndex-1));
            quickSort(array,(pivotIndex+1),rigth);
        }
}

int partition (int array [],int left, int rigth){
        int i = left-1;

        int pivot = array[rigth];

        int temp;

        for(int j = left; j <= rigth-1; j++){
            if(array[j] <= pivot){
                i++;
                swap(&array[j], &array[i]);
            }
        }
        swap(&array[i+1],&array[rigth]);

return (i+1);

}

void swap(int *position1, int *position2){
    int temp;
    temp = *position1;
    *position1 = *position2;
    *position2 = temp;

}









