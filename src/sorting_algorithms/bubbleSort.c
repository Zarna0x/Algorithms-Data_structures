#include <stdio.h>
#include <stdlib.h>

void printArray(int *,int);
int* bubbleSort(int *,int);
int main () {

int Arr[] = {5,7,9,1,3,15,30,2};
int arraySize = sizeof(Arr)/sizeof(int);


printf("___Before buble Sort___\n");
printArray(Arr,arraySize);
printf("\n\n\n");


int *sortedArr = bubbleSort(Arr,arraySize);


printf("___After buble Sort___\n");
printArray(sortedArr,arraySize);
printf("\n\n\n");


 return 0;
}


void printArray(int *arr,int arrSize) {
  int i;
  for (i = 0; i < arrSize; i++) {
     printf("%d,",arr[i]);
  }

}


int* bubbleSort(int* Arr, int n) {
  int i,j,temp, swapped;
  for ( i = 0; i < n-1; i++) {
     swapped = 0;
     for (j = 0; j< n-1-i; j++) {

        if (Arr[j] > Arr[j+1]) {
            //swap
            temp = Arr[j];
            Arr[j] = Arr[j+1];
            Arr[j+1] = temp;
            swapped = 1;
        }


     }
     if (swapped == 0) break;
  }
  return Arr;
}


/*
Time Complexity  = O(n^2)

T(n) = C(n-1) + C(n-2) + C(n-3) + C(n-(n-1))
= C(n(n-1)/2) = O(n^2)

*/
