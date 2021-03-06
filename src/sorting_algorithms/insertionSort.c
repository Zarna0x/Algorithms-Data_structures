#include <stdio.h>
#include <stdlib.h>

/*
 Worst case time complexity = O(n^2)
 T(n) = C1(n-1) + C3(n-1) + C2 + 2C2 + 3C2 + ... + (n-1)C2
 = (C1+C3)(n-1) + C2(n(n-1)/2) = O(n^2)
*/

void printArray(int *,int);
int* insertionSort(int *,int);
int main () {

int Arr[] = {5,7,9,1,3,15,30,2,2};
int arraySize = sizeof(Arr)/sizeof(int);


printf("___Before buble Sort___\n");
printArray(Arr,arraySize);
printf("\n\n\n");


int *sortedArr = insertionSort(Arr,arraySize);


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


int* insertionSort(int* Arr, int n) {
  int i,holder,element;
  for (i = i; i < n; i++) {
     element = Arr[i];
     holder = i;
     while (holder > 0 && Arr[holder - 1] > element) {
        Arr[holder] = Arr[holder-1];
        holder = holder - 1;
     }
       Arr[holder] = element;

  }
  return Arr;
}


