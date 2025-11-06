#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void traversal(struct node* ptr){
    while(ptr != NULL){
        printf("element: %d\n", ptr -> data);
        ptr = ptr-> next;
    }
}

struct node* insertBeg(struct node* head, int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p-> data = data;
    p-> next = head;
    return p;
}

struct node* insertBtw(struct node* head, int data, int index){
    struct node* p =head;
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    int i=0;
    while(i != index){
        p = p->next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

struct node* insertEnd(struct node* head, int data){
    struct node* p =head;
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    while(p -> next != NULL){
        p = p-> next;
    }
    ptr -> data = data;
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

int main(){
    struct node*head;

    head = (struct node*)malloc(sizeof(struct node));

    head -> data = 10;
    head-> next = NULL;

    printf("\nelements before operation: \n");
    traversal(head);

    head = insertBeg(head, 1);
    head = insertEnd(head, 60);
    printf("\nelements after operation: \n");
    traversal(head);

    return 0;
}