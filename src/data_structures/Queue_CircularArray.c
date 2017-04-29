#include <stdio.h>
#include <stdbool.h>


// Queue implementation using circular array
#define SIZE 10
int A[SIZE];

int front = -1;
int rear  = -1;

bool isEmpty();
bool isFull();
int Front(); // returns Front element of queue
void Enqueue(int); // Add item in queue
void Dequeue(); // push element from queue
void Print();

int main () {
  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  Enqueue(4);
  Enqueue(5);
  Dequeue();
  Enqueue(99);
  Enqueue(99);
  Enqueue(99);
  Enqueue(99);
  Enqueue(99);
  Dequeue();
  Dequeue();
  Enqueue(77);
  Enqueue(99);
  Enqueue(55);

  Print();

  printf("==%d AND %d==",front,rear);


  return 0;
}

bool isEmpty () {
  if (rear == -1 && front == -1) {
     return true;
  }

  return false;
}

bool isFull () {
  if ( (rear+1) % SIZE == front ) {
      return true;
  }

  return false;
}

void Enqueue (int x) {
   if (isFull()) {
       puts("Queue is full!\n");
       return;
   }else if (isEmpty()) {
        front = rear = 0;
   }else {
      rear = (rear+1)%SIZE;
   }

   A[rear] = x;

}

int Front () {
  if (isEmpty()) {
    puts("Queue is empty");
    return;
  }

  return A[front];

}


void Dequeue () {
  if (isEmpty () ) {
     puts("Queue is empty!!\n");
     return ;
  }else if (front == rear) { // There is only one element so make queue empty
      front = rear = -1;
  }

   front = (front + 1)%SIZE;

}


void Print() {

  int count = (rear + SIZE - front) % SIZE + 1; // Number Of Elements in queue
  int i;

  for  ( i = 0; i <= count; i++) {
     int index = (front + i) % SIZE;
     printf("%d, ",A[index]);

  }

  printf("\n\n");
}
