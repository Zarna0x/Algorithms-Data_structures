#include <stdio.h>

void merge(int* A,int* B,int* C,int a_Size,int b_Size) {
  int i = 0, j = 0, k=0;

  while(i < a_Size && j < b_Size) {
    if (A[i] <= B[j]) {
       C[k] = A[i];
       k++;
       i++;
    } else {
      C[k] = B[j];
      k++;
      j++;
    }
  }

  while (i < a_Size) {
    C[k] = A[i];
    k++;
    i++;
  }

  while (j < b_Size) {
   C[k] = B[j];
    k++;
    j++;
  }

}

void mergeSort(int *Arr,int n) {

  if (n < 2) {
     return;
  }

  int mid = n/2;

  //create spaces for two array in heap
  int *left  =  (int*)malloc(mid*sizeof(int));
  int *right = (int*)malloc((n-mid) * sizeof(int));

  //Fill arrays
  int i,j;

  for (i=0; i<mid;i++) {
    left[i]  = Arr[i];
  }

  for (j=mid; j<n;j++) {
     right[j-mid] = Arr[j];
  }

  mergeSort(left,mid);
  mergeSort(right,n-mid);
  merge(left,right,Arr,mid,n-mid);

  free(left);
  free(right);
}

void printArray(int* Arr,int n){
  int i;
  for (i = 0; i<n ; i++) {
    printf("%d, ",Arr[i]);
  }
}

int main() {

int Arr[] = {4,3,2,1};

mergeSort(Arr,sizeof(Arr)/sizeof(int));
printf("__SORTED__\n");
printArray(Arr,sizeof(Arr)/sizeof(int));
 return 0;
}
