//singled linked l__cpp_initializer_lists

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};
Node* head = NULL;
void display()
{
    if (head==NULL)
    {
        cout<<"List is empty";
        return;
    }
    Node* temp = head;
    cout<<"Double Linked List :";
    while (temp!=NULL)
    {
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void create()
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
        newNode->prev = NULL;
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
            newNode->prev = temp;
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
void deletenode()
{
    int p;
    cout<<"Enter the postion:";
    cin>>p;
    if (head==NULL)
    {
        cout<<"Empty list";
        return;
    }
    Node* temp = head;
    if (p==1)
    {
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = NULL;
    for (int i =0;i<p-1 && temp!=NULL;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp==NULL)
    {
        cout<<"Position out of range";
        return;
    }
    prev->next = temp->next;
    delete temp;
}
void reverse()
{
    Node* temp = NULL;
    Node* curr =head;
    while (curr!=NULL)
    {
        temp = curr->prev;
        curr->prev=curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp!=NULL)
    head = temp->prev;
}
Node* head2 = NULL;
void concate()
{
    if (head==NULL)
    {
        head = head2;
        return;
    }
    Node*temp = head;
    while (temp->next = NULL)
        temp= temp->next;
    temp->next = head2;
}
int main()
{
    int choice;
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
        case 4:
            deletenode();
            break;
        case 3:
            cout<<"Exiting...";
            break;
            default:
             cout<<"Invalid Choice Try again "<<endl;
        }
    }while (choice!=3);
    return 0;
}