/*   Author:             Fabiola Villanueva
 *   Description:        Linked List Implementation of Binary Search Trees (Iterative)
 *                       Personal Project
 *   Specifications:     Iterative (~insertion, !tree traversal)
 *   Date:               Nov 15, 2023
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 15

//typedef definitions
typedef enum BOOL {FALSE, TRUE} Boolean;

typedef struct treeNode {
     int data;
     struct treeNode *left;
     struct treeNode *right;
} treeType, *treePtr;

//function prototypes
Boolean initialize (treePtr *root);
void insertSet (treePtr *root, int arr[]);
Boolean isMember (treePtr root, int elem);
void insertMember (treePtr *root, int elem);
void inorderDisplay (treePtr root);
void preorderDisplay (treePtr root);
void postorderDisplay (treePtr root);
void deleteMember (treePtr *root, int elem);

int main() {
     system ("cls");
     treePtr head;
     int set[MAX] = {21, 33, 43, 11, 11, 67, 32, 75, 91, 15, 3, 21, 43, 67, 66};
     int i, elem;
     Boolean ans = TRUE;

     printf("<< BEGIN >>\n\n");
     printf("<< 0. Initialize >>\n");
     if (initialize (&head)) {
          printf("\thead = NULL\n");
          printf("\tHead of tree is now intialized to NULL.\n");
     }

     printf("\n<< 1. Insert Set Into Tree >>\n");
     
     printf("\tSet = {");
     for (i = 0; i < MAX; ++i) {
          printf("%d", set[i]);
          if (i < MAX-1) {
               printf(", ");
          }
     }
     printf("}");

     printf("\n\tInserting all elements in the set into the tree...\n\n");
     insertSet (&head, set);
     
     printf("\n\t> User input of elements into the tree:\n");
     do {
          printf("\n\tAdd an element into the tree? < 1-yes / 0-no >\n");
          printf("\tAns: ");
          scanf("%d", &ans);

          if (ans == TRUE) {
               printf("\tInput member to insert: ");
               scanf("%d", &elem);
               insertMember (&head, elem);
          }
     } while (ans == TRUE);

     printf("\n<< 2. Displaying Binary Search Tree >>\n");
     
     printf("\n\t> Inorder Traversal\n\t\t");
     inorderDisplay (head);

     printf("\n\t> Pre-Order Traversal\n\t\t");
     preorderDisplay (head);

     printf("\n\t> Post-Order Traversal\n\t\t");
     postorderDisplay (head);

     printf("\n\n<< 3. Delete an Element From the Tree >>\n");

     printf("\n\n<< END >>\n\n");
     return 0;
}

//function definition
Boolean initialize (treePtr *root) {
     *root = NULL;
     return (*root == NULL) ? TRUE: FALSE;
}

void insertSet (treePtr *root, int arr[]) {
     treePtr temp;
     int i;

     for (i = 0; i < MAX; ++i) {                  //per iteration of the array is an element to insert into the tree
          insertMember (root, arr[i]);        //if unique element then insert into tree
     }
}

Boolean isMember (treePtr root, int elem) {                                               //recommendation: isMember will return the address of elem if found,
     while (root != NULL && root->data != elem) {                                         //else return the pointer pointing to NULL
          root = (elem < root->data) ? root->left: root->right;
     }
     return (root != NULL) ? TRUE: FALSE;                                                  //is a member if trav is pointing to an existing node
}

void insertMember (treePtr *root, int elem) {
     treePtr *trav = root, temp;

     if (isMember(*trav, elem) == FALSE) {                                                //recommenadtion: if isMember returns a pointer to NULL then insert elem
          printf("\t[%d] is a unique element. Inserting into tree...\n", elem);           //else, that means that if pointer is a node, then elem is a member of tree
          
          temp = malloc(sizeof(treeType));
          temp->left = NULL; 
          temp->right = NULL;
          temp->data = elem;

          while (*trav != NULL) {                                                         //with recommendations applied, there will no longer be another traversal 
               trav = (elem < (*trav)->data) ? &(*trav)->left: &(*trav)->right;           //to locate the position to insert the elem
          }
          *trav = temp;
     } else {
          printf("\t[%d] is NOT a unique element.\n", elem);
     }
}

void inorderDisplay (treePtr headPtr) {                //recursive
     if (headPtr != NULL) {                            //visits every left child, prints the data pasaka once it reaches the bottom
          inorderDisplay (headPtr->left);              //after printing each left child, then to parent, then to right child
          printf("[%d]", headPtr->data);               //function is removed from execution stack once condition meets NULL
          inorderDisplay (headPtr->right);
     }
}

void preorderDisplay (treePtr headPtr) {
     if (headPtr != NULL) {
          printf("[%d]", headPtr->data);
          preorderDisplay (headPtr->left);
          preorderDisplay (headPtr->right);
     }
}

void postorderDisplay (treePtr headPtr) {
     if (headPtr != NULL) {
          preorderDisplay (headPtr->left);
          preorderDisplay (headPtr->right);
          printf("[%d]", headPtr->data);
     }
}

// void deleteMember (treePtr *root, int elem) {                                                  //we are traversing using a parent pointer
//      if (isMember (*root, elem))
// }