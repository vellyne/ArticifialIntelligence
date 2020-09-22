#include<stdio.h>
#include<stdlib.h>
   
struct node{
    int key;
    struct node *left, *right;
};
   
struct node *newNode(int value){
    struct node *temp =  (struct node*)malloc(sizeof(struct node));
    temp->key = value;
    temp->left = NULL;
	temp->right = NULL;
    return temp;
}
   
void print(struct node *root){
    if (root != NULL){
        print(root->left);
        printf("%d\n", root->key);
        print(root->right);
    }
}
   
struct node* insert(struct node* node, int key){
    if (node == NULL){
		return newNode(key);
	}
    if (key < node->key){
		node->left  = insert(node->left, key);
	}
    if (key > node->key){
		node->right = insert(node->right, key);
	}
  
    return node;
}
   
int main(){
	
    struct node *root = NULL;
    
    root = insert(root, 4);
    
    insert(root, 2);
    insert(root, 5);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
   
    print(root);
   
    return 0;
}
