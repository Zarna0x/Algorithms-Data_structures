#include <stdio.h>
#include <stdlib.h>

void printArray(int *,int);
int* selectionSort(int *,int);
int main () {

int Arr[] = {5,7,9,1,3,15};
int arraySize = sizeof(Arr)/sizeof(int);


printf("___Before Selection Sort___\n");
printArray(Arr,arraySize);
printf("\n\n\n");


int *sortedArr = selectionSort(Arr,arraySize);


printf("___After Selection Sort___\n");
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

int* selectionSort (int* Arr,int arrSize) {
  int i,j,min,temp;

  for (i = 0; i < arrSize; i++) {
     // find index of min value
     min = i;
     for (j = i+1; j < arrSize; j++) {
        if (Arr[j] < Arr[min]) {
            min = j;
        }
     }

     // Swap positions
     temp = Arr[i];
     Arr[i] = Arr[min];
     Arr[min] = temp;
  }

  return Arr;
}
