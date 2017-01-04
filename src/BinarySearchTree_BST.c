#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


// Binary Search Tree Implementation in C;
struct BST_Node {
  int data;
  struct BST_Node* left;
  struct BST_Node* right;
};


/*
  @desc   => Get new BST_Node allocated in the heap section of memory
  @param  => int data (Value of node)
  @return => memory addres of newly allocated BST_Node in the heap
*/
struct BST_Node* GetNewBSTNode(int data) {
    struct BST_Node* NewNode = (struct BST_Node*)malloc(sizeof(struct BST_Node));

    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
}

/*
  @desc   => Insert new node in the Tree
  @param1 => struct BST_NODE** root (addres of root node)
  @param2 => int data, (value to be Inserted)
  @return void
*/
void BST_Insert(struct BST_Node** root,int data) {
    if ( *root == NULL ) { // If Tree is Empty
        *root = GetNewBSTNode(data);
        return;
     }

      else if (data <= (*root)->data) {
           // Go Left Subtree
           BST_Insert(&((*root)->left),data);
      }

      else {
          // Rigth Subtree
         BST_Insert(&((*root)->right),data);
      }


}

/*
  @desc   => Search If data specified by param is part of tree
  @param1 => struct BST_NODE** root (addres of root node)
  @param2 => int data, (value to be searched)
  @return bool (True if data is found, False if data is not found)
*/
bool BST_Search (struct BST_Node** root, int data) {
   if ((*root) == NULL) {
       return false;
   }

   if ((*root)->data == data) {
      return true;
   }

   // If data is less than root data Search at the left part of tree using recursion
   if (data <= (*root)->data) {
        BST_Search(&((*root)->left),data);
   }
    // Search at the right part of the tree
   else  {
      BST_Search(&((*root)->right),data);
   }
}

/*
 @desc   => find Min Element of Tree
 @param1 => pointer of struct node root
 @return => Min Value Of Tree (pointer of node)
*/

struct BST_Node* BST_FindMin (struct BST_Node* root) {
  if ( root == NULL) {
      return ; // Tree is Empty
  }

  if (root->left == NULL) {
      return root; // There is only one element in the Tree
  }

  else  {
    BST_FindMin(root->left);
  }
}


/*
 @desc   => find Max Valued Element of Tree
 @param1 => pointer of struct node root
 @return => Max Value Of Tree (pointer of node)
*/

struct BST_Node* BST_FindMax (struct BST_Node* root) {
  if ( root == NULL) {
      return ; // Tree is Empty
  }

  if (root->right == NULL) {
      return root; // There is only one element in the Tree
  }

  else  {
    BST_FindMax(root->right);
  }
}


/* 
  @desc   => BST Insert Iterative Solution;
  @param1 => address of root pointer 
  @param2 => data to insert
  @return => void
*/
void Insert (struct BST_Node** root, int data) {
   if ((*root) == NULL) {
      *root = GetNewBSTNode(data); // If Tree Is Empty
      return ;
   }

     struct BST_Node *tmp, *offsetNode;
     tmp = *root;
     int count = 1;
     while (tmp != NULL) {
         if (data <= tmp->data) {
              offsetNode = tmp;
              tmp = tmp->left; 
         }

         else {
             offsetNode = tmp;
             tmp = tmp->right;

         }

         count++;
     }

     if (data <= offsetNode->data) {
         offsetNode->left = GetNewBSTNode(data);
     }

     else if (data >= offsetNode->data) {
          offsetNode->right = GetNewBSTNode(data);
     }

}

/*
  @desc => find height of binary search tree
*/

int BST_FindHeight (struct BST_Node* root) {
  if (root == NULL) {
       return -1;
  }



  int leftHeight  = BST_FindHeight(root->left);
  int RightHeight = BST_FindHeight(root->right);


  return MAX(leftHeight,RightHeight) + 1;



}
/*
  @desc   => Depth first traversial of Binary Search Tree, (Preorder)
  @param  => pointer of root node
  @return => void
*/
void BST_PreorderPrint (struct BST_Node* root) {
  if (root == NULL) {
     return ;
  }

  printf(" %d ",root->data);
  BST_PreorderPrint(root->left);
  BST_PreorderPrint(root->right);
}


/*
  @desc   => Depth first traversial of Binary Search Tree, (Inorder) (items will be sorted)
  @param  => pointer of root node
  @return => void
*/
void BST_InorderPrint (struct BST_Node* root) {
  if (root == NULL) {
     return ;
  }


  BST_InorderPrint(root->left);
  printf(" %d ",root->data);
  BST_InorderPrint(root->right);
}

bool isBstUtil (struct BST_Node* root,int MinValue,int MaxValue) {
  if (root == NULL) {
      return true;
  }

  if (root->data > MinValue && root->data < MaxValue
    && isBstUtil(root->left,MinValue,root->data)
    && isBstUtil(root->right,root->data,MaxValue)
  ) {
    return true;
  }

  else {

     return false;
  }


}

bool isBST (struct BST_Node* root) {
   return isBstUtil(root,INT_MIN,INT_MAX);
}


void BST_Delete (struct BST_Node** root,int data) {
   if (*root == NULL) {
       return ;
    }

    if (data < (*root)->data) {
       BST_Delete(&((*root)->left),data);
   }

   else if (data > (*root)->data) {
      BST_Delete(&((*root)->right),data);
   }

   else {
      if ( (*root)->left == NULL && (*root)->right == NULL ) {
            free(*root);
            *root = NULL;
      }

      else if ( (*root)->left == NULL ) {
          struct BST_Node* tmp = *root; // node to delete
          *root = tmp->right;
          free(tmp);

      }

      else if ( (*root)->right == NULL ) {
          struct BST_Node* tmp = *root;
          *root = tmp->left;
          free(tmp);
      }

      else  { // if node has two child
        struct BST_Node* MinVal = BST_FindMin((*root)->right); 
        (*root)->data = MinVal->data;
         BST_Delete(&((*root)->right),MinVal->data);

      }
   }
}

int main () {

  struct BST_Node* root = NULL;

  BST_Insert(&root,15);
  BST_Insert(&root,10);
  BST_Insert(&root,20);
  BST_Insert(&root,700);
  BST_Insert(&root,99);
  printf("%d",BST_Search(&root,0));
  struct BST_Node* Min = BST_FindMin(root);
  struct BST_Node* Max = BST_FindMax(root);
  printf("\n Min -> %d \n Max ->%d",Min->data,Max->data);
  int maxheight = BST_FindHeight(root);

  printf("Max height is -> %2d",maxheight);
  
  return 0;
}
