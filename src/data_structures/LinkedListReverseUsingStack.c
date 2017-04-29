#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node* next;
};

struct stack_node{
  struct node* data;
  struct stack_node* next;
};

struct stack_node* top; // top of Stack (last element index)

struct node* head ;

//Stack functions



void Push (struct node** PointerOfNode) {
 // insert at head
  struct stack_node* temp = (struct stack_node*)malloc(sizeof(struct stack_node));
  temp->data = *PointerOfNode;
  temp->next = top;
  top = temp;
}

void Pop () {
// delete last element
  if (top == NULL) {
     return;
  }
  struct stack_node* temp = top;
  top = top->next;
  free(temp);

}

int countStackElements () {
  struct stack_node* stk = top;
  int i = 0;
  while (stk != NULL) {
    i++;
    stk = stk->next;
  }

  return i;
}

PrintListUsingStack () {
  struct stack_node* tmp = top;

  printf("Stack List: ");

  while (tmp != NULL) {
   printf(" %d, ",tmp->data->data);
   tmp = tmp->next;
  }
}

// </STACK FUNCTIONS>


// <LINKED LIST FUNCTIONS>
void Insert(int x) {
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data =x;
  tmp->next = head;
  head = tmp;
}


void Print() {
 struct node* tmp = head;
 printf("Linked List: ");
 while (tmp != NULL) {
  printf(" %d, ",tmp->data);
  tmp = tmp->next;
 }
}

void ReverseUsingStack () {
  struct node* tmpNode = head;
  // FIll stack with nodes


  while (tmpNode != NULL) {

    Push(&tmpNode);
    tmpNode = tmpNode->next;
  }
 struct node* tmp = top->data;
 head = tmp;
 Pop();
 int i = 0;
 while (i < countStackElements()) {

    tmp->next = top->data;
    Pop();
    tmp = tmp->next;

 }
 tmp->next = NULL;
}
// </LINKED LIST FUNCTIONS>

 int main () {

  int i = 1;
  while (i < 7) {
    Insert(i);
    i++;
  }
  Print();
  ReverseUsingStack();
  puts("\n");
  Print();
  //PrintListUsingStack();
    return 0;
 }
