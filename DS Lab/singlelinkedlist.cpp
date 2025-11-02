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
void insert()
{
    int p,val;
    cout<<"Enter the position to be insert :";
    cin>>p;
    cout<<"Enter the Value :";
    cin>>val;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (p==1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp =head;
    for (int i =0;i<p-1 && temp!=NULL;i++)
    {
        temp = temp->next;
    }
    if (temp==NULL)
    {
        cout<<"Position is out of range";
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    }

int main()
{
    int choice;
    cout<<"Enter the choice:";
    do
    {
        cin>>choice;
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            cout<<"Exiting...";
            return 0;
            default:
             cout<<"Invalid Choice Try again "<<endl;
        }
    }while (choice!=3);
}