#include <stdio.h>
#include <stdlib.h>

void printArray(int *,int);
int* bubbleSort(int *,int);
int main () {

int Arr[] = {5,7,9,1,3,15,30,2,3,5};
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
  int i,j,temp;
  for ( i = 0; i < n-1; i++) {
     for (j = 0; j< n-1-i; j++) {
        if (Arr[j] > Arr[j+1]) {
            //swap
            temp = Arr[j];
            Arr[j] = Arr[j+1];
            Arr[j+1] = temp;

        }

     }
//     break;
  }
  return Arr;
}
