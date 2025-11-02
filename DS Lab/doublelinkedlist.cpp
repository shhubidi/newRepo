// Created by harman on 2/11/25.
//double Linkled lIst
//singled linked l__cpp_initializer_lists

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;
void display()
{
    Node* temp = head;
    cout<<"Single Linked List :";
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
Node* create()
{
    int n,value;
    cout<<"Enter the number of node: ";
    cin>>n;
    for (int i =0;i<n;i++)
    {
        cout<<"Enter the value "<<i+1<<": ";
        cin>>value;
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head==NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }
    display();
}

int main()
{
    Node* list1= NULL;
    create();
    return 0;
}
