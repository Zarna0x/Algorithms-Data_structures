#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head;

bool isEmpty() {
   return head == NULL;
}

int countNodes() {
   struct node* counter_node = head;

   int i = 0;
   while (counter_node != NULL) {
      i++;
      counter_node = counter_node->next;
   }

   return i;
}

struct node* GetNewNode(int x) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;

}

void InsertAtHead( int x ) {
   struct node* temp = GetNewNode(x);
   if (head == NULL) {
      head = temp;
      return;
   }
     head->prev = temp;
     temp->next = head;
     head       = temp;
 }

 void InsertAtTail (int x) {
     struct node* newNode = GetNewNode(x);
     struct node* temp    = head;

     if (head == NULL) {
        head = newNode;
        return;
     }

     //Iterate right
    while (temp->next != NULL) {
       temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;


 }

void ReversePrint() {
	struct node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void Print () {
  struct node* temp = head;
  printf("Forward: ");
  while (temp != NULL) {
    printf("%d, ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void DeleteHead () {
  if (head->next == NULL) {
     head = NULL;
     return;
  }


  head = head->next;
  head->prev = NULL;

}

void DeleteNth(int n){
  if(n > countNodes()){
     return;
  }
  struct node* temp = head;
  int i;
  for (i = 0; i <  n-2; i++) {
     temp = temp->next;
  }
   struct node* temp2 = temp->next;
   temp->next  = temp2->next;
   temp2->next->prev = temp;
   free(temp2);


}

void InsertNth (int x,int n) {
  if(n > countNodes()){
     return;
  }
  struct node* newNode = GetNewNode(x);
  if (n == 1) {

     head->prev    = newNode;
     newNode->next = head;
     head = newNode;
     return ;
  }

  int i;
  struct node* tmp_head = head;
  for (i = 0; i < n-2; i++) {
     tmp_head = tmp_head->next; // 2th node
  }

  newNode->next = tmp_head->next;
  tmp_head->next->prev = newNode;
  tmp_head->next = newNode;
  newNode->prev  = tmp_head;


}


void DeleteByValue (int x){
  struct node* tmp_ptr = head;
  int i = 1;
  bool check_if = false;
  int pos;

  while (tmp_ptr != NULL){
     if (tmp_ptr->data == x) {
        check_if = true;
        pos = i;
        break;
    }

     i++;
     tmp_ptr = tmp_ptr->next;
  }



   // Now delete post-th element
   struct node* temp = head;
   int j ;
   for (j = 0; j < pos - 2; j++) {
       temp = temp->next;
   }


   temp->next = tmp_ptr->next;
   tmp_ptr->next->prev = temp;
   free(tmp_ptr);
}

bool Exists (int x) {
   struct node* tmp = head;
   bool exists = false;
   int i;
   while (tmp != NULL){
     if (tmp->data == x) {
        exists = true;
        break;
    }

     i++;
     tmp = tmp->next;
  }

  return exists;
}

void DeleteLast(){
  struct node* tmp = head;
  while (tmp->next != NULL) {
     tmp = tmp->next;
  }
    tmp->prev->next = NULL;
    tmp = NULL;
    free(tmp);

}

void reverse(){
  struct node *currNode,*nextNode,*prevNode;
  currNode = head;

  while (currNode != NULL) {
     // set Next
     nextNode = currNode->next; // next = 2

     currNode->next = prevNode; // cuurnext =ĵnull

     prevNode = currNode;
     currNode = nextNode;
  }
     head = prevNode;

//printf("--%d--",head->next->next->data);
}

void clear() {
  struct node* current = head;
  struct node* next;

  while (current!= NULL) {
        next = current->next;
        free(current);
        //move one
        current = next;
  }

   head = NULL;


}

void Swap (int n) {
  if(n >= countNodes()){
     return;
  }

  struct node* tmp_ptr = head;

  // get n-th node pointer
  int i;
  for (i = 0; i < n-1 ;i++ ) {
     tmp_ptr = tmp_ptr->next;
  }
  // Swap adjacent nodes;
  struct node* nextNode = tmp_ptr->next;

  // Swap


  tmp_ptr->prev->next  = nextNode;
  nextNode->next->prev = tmp_ptr;

  tmp_ptr->next = nextNode->next;
  nextNode->prev = tmp_ptr->prev;

  tmp_ptr->prev  = nextNode;
  nextNode->next = tmp_ptr;

}

void SwapLeft(int n) {
if(n >= countNodes()){
     return;
  }

  struct node* tmp_ptr = head;

  // get n-th node pointer
  int i;
  for (i = 0; i < n-1 ;i++ ) {
     tmp_ptr = tmp_ptr->next;
  }
  // Swap adjacent nodes;
  struct node* prevNode = tmp_ptr->prev;

  prevNode->prev->next = tmp_ptr;
  tmp_ptr->next->prev  = prevNode;

  tmp_ptr->prev  = prevNode->prev;
  prevNode->next = tmp_ptr->next;

  tmp_ptr->next  = prevNode;
  prevNode->prev = tmp_ptr;
  //printf("--%d--",tmp_ptr->data);


}

void ChangeNodePos(int n, int new_position) {
 if(n > countNodes()){
     return;
  }

  if (new_position == 1) {
     struct node *pos = head;
     // get Pos-th node
     int i;
     for (i = 0; i < n-1 ;i++ ) {
       pos = pos->next;
     }
       InsertAtHead(pos->data);
       DeleteNth(i+2);


       return ;
  }

  if (new_position > n) {
   // Swap Right
     int iter = new_position - n;
     int i = 1;
     while ( i <= iter) {
        Swap(n);
        i++;
        n++;
     }

  }else if (new_position < n) {
     // Swap Left
     int iter = n - new_position;
     int i = 1; // i = 5
     while (i <= iter ) {
        SwapLeft(n);
        i++;
        n--;
     }
    return ;
  }

}
#endif // DOUBLYLINKEDLIST_H
