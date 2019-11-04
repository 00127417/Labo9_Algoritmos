#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
using namespace std;

struct node{int key;
struct node *left, *right;};// A utility function to create a new BST node
struct node *newNode(int item){
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root){

if (root != NULL){
inorder(root->left);
printf("%d \n", root->key);
inorder(root->right);
}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key){
/* If the tree is empty, return a new node */
if (node == NULL) return newNode(key);
/* Otherwise, recur down the tree */
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
/* return the (unchanged) node pointer */
return node;}


void preorder(struct node *root){

if (root != NULL){
printf("%d \n", root->key);
preorder(root->left);
preorder(root->right);

}
}

node* LCA(node * root, int n1,int n2) 
{ 
    // Your code here 
    if (root == NULL) 
       return root; 
    if (root->key == n1 || root->key == n2) 
       return root; 
  
    node* left = LCA(root->left, n1, n2); 
    node* right = LCA(root->right, n1, n2); 
  
    if (left != NULL && right != NULL) 
         return root; 
    if (left != NULL) 
        return LCA(root->left, n1, n2); 
  
    return LCA(root->right, n1, n2); 
} 

int findLevel(Node *root, int k, int level) 
{ 
    if(root == NULL) return -1; 
    if(root->key == k) return level; 
  
    int left = findLevel(root->left, k, level+1); 
    if (left == -1) 
       return findLevel(root->right, k, level+1); 
    return left; 
} 
  
int findDistance(Node* root, int a, int b) 
{ 
    // Your code here 
    Node* lca = LCA(root, a , b); 
  
    int d1 = findLevel(lca, a, 0); 
    int d2 = findLevel(lca, b, 0); 
  
    return d1 + d2; 
}

int main(){
    
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // print inoder traversal of the BST
    //inorder(root);
    preorder(root);
    cout << "LCA(30, 70) = " << LCA(root, 30, 70)->key;
    return 0;
}
