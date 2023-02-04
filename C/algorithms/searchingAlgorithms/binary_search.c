/***************************************************************************
*   This is an implementation of binary search algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition : binary search is one of the most used searching algorithm
*   it consists on finding the index of the target element comparing it
*   with the midle index in the sorted array...
*   Runnig time: O(n*logn)
*
*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
int binarySearch (int array[], int size, int keyValue );

int size;
int result;

int
main(void) {
    //binary search works only with sorted array
    int myArray [] = {42,43,44,45,46,47,75,76,77,78,109,1010,120,130};

    //this operation guive us the real size of the array
    size = sizeof(myArray)/sizeof(int);

    result = binarySearch(myArray, (size-1), 45);
    (result == -1 )
    ? printf("target not found\n")
    : printf("target %d found at position %d\012",myArray[result], result);

    return 0;
}


/*
* binary search implementation
* recives an array and the target key and returns the
* target index in the array or a negative value if the target
* is not in the array
*/

int binarySearch(int array[], int size , int keyValue){

    int key;
    int begin, midle, end;
     if(size == 0){
        perror("Error empty array");
        exit(1);
    }

    key = keyValue;
    begin = 0;
    end = size;
    midle = (begin + end)/2;

    while(begin <= end){

        if(key == array[midle]){

            return (midle);
        }
        if(key > array[midle]){
            begin = midle + 1;

        }else if( key < array [midle] ){
            end = midle - 1;
        }
        midle = (begin + end) / 2;
    }

  return (-1);
}


//compile : gcc -o  binary binary_search.c
//execute : time ./binary
/*output:
    target 45 found at position 3

    real    0m0.002s
    user    0m0.002s
    sys     0m0.001s

 */
