// Created by harman on 3/11/25.
//binary search tree

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* create(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void inorder(Node* root)
{
    if (root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"";
    inorder(root->right);
}
void preorder(Node* root)
{
    if (root==NULL)
        return;
    cout<<root->data<<"";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if (root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"";
}
Node* search(Node* root,key)
{
    if (root==NULL||root==key)
        retrun root;
    if (key<root->data)
        return search(root->left,key);
    else
        retrun search(root->right,key);
}
Node* findmind(Node* node)
{
    while (node && node->left!=NULL)
        node = node->left;
    return node;
}
Node* deletenode(Node* root,int key)
{
    if (root==NULL)
        return root;
    if (key<root->data)
        root->left = deletenode(root_>left,key);
    else if (key>root->data)
        root->right = deletenode(root_>right,key);
    else
    {
        if (root->left==NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp =findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right,temp->data);
    }
    return root;
}
