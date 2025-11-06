#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* create(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data  = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data); 
    }
}

struct node* insert(struct node* root, int key){
    if(root == NULL){
        return create(key);
    }
    else if(key < root -> data){
        root -> left = insert(root -> left, key);
    }
    else{
        root -> right = insert(root -> right, key);
    }
    return root;
}

struct node* search(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(root -> data == key){
        return root;
    }
    else if(key < root -> data){
        return search(root -> left, key);
    }
    else{
        return search(root -> right, key);
    }
    return root;
}

struct node* predecessor(struct node* root){
    root = root -> left;
    while(root -> right != NULL){
        root = root -> right;
    }
    return root;
}

struct node* delete(struct node* root, int key){
    struct node*iPre;
    if(root == NULL){
        return NULL;
    }
    else if(key < root-> data){
        root -> left = delete(root -> left, key);
    }
    else if(key > root-> data){
        root -> right = delete(root -> right, key);
    }
    else{
        if(root -> left == NULL && root -> right == NULL){
        free(root);
        return NULL;
        }
        else if(root -> left == NULL){
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            struct node* temp = root -> left;
            free(root);
            return temp;
        }
        else{
            iPre = predecessor(root);
            root -> data = iPre -> data;
            root -> left = delete(root -> left, iPre -> data);
        }
    }
    return root;
}

int main(){
    struct node* p = NULL;
    p = insert(p, 5);
    p = insert(p, 10);
    p = insert(p, 3);
    p = insert(p, 7);
    p = insert(p, 14);
    p = insert(p, 4);

    inorder(p);
    
    p = delete(p, 3);
    printf("\nafter deletion: ");
    inorder(p);
    
    return 0;
}