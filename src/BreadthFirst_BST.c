#include <iostream>
#include <queue>

//using namespace std;

struct node {
  char data;
  node* left;
  node* right;
};

void LevelOrder(node* root){
   if (root == NULL) {
      return ;
   }
    std::queue<node*> Q;
    Q.push(root);
    // Print child nodes and save discovered nodes in the queue
    while (!Q.empty()) {
       node* current = Q.front();
       std::cout << current->data << " ";
       if (current->left != NULL) {
          Q.push(current->left);
       }

       if (current->right != NULL) {
          Q.push(current->right);
       }

       Q.pop();
    }
}

node* GetNewBSTNode(char data) {
  node* newNode = new node(); // reserve memory in heap
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void Insert(node** root,char data) {
  if (*root == NULL ) { //Tree is empty
     *root = GetNewBSTNode(data);
     return ;
  }

  else if (data <= (*root)->data) {
       Insert(&((*root)->left),data );
  }

  else if (data >= (*root)->data) {
    Insert(&((*root)->right),data );
  }

}

int main () {
 node* root = NULL;

 std::cout << "Enter Char: ";
 char t;

 while (std::cin>>t) {
   std::cout << "Enter Char: ";
  if (t == 'q') {
      break;
  }
    Insert(&root,t);
 }

LevelOrder(root);
 return 0;
}
