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

struct node* create(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
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

struct node* delBeg(struct node* head){
    struct node* ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct node* delBtw(struct node* head, int index){
    struct node* ptr = head;
    struct node* p = head -> next;
    int i = 0;
    while(i != index-1){
        ptr = ptr -> next;
        p = p -> next;
    }
    ptr -> next = p -> next;
    free(p);
    return head;
}

struct node* delEnd(struct node* head){
    struct node* ptr = head;
    struct node* p = head -> next;
    while(p -> next != NULL){
        ptr = ptr -> next;
        p = p -> next;
    }
    ptr -> next = NULL;
    free(p);
    return head;
}

struct node* reverse(struct node* head){
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

struct node* merge(struct node* h1, struct node* h2){
    struct node* ptr = h1;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = h2;
    return h1;
}

struct node* sortedMerge(struct node* h1, struct node* h2){
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct node* result = NULL;

    if(h1 -> data <= h2 -> data){
        result = h1;
        result -> next = sortedMerge(h1 -> next, h2);
    }
    else{
        result = h2;
        result -> next = sortedMerge(h1, h2 -> next);
    }
    return result;
}

int main(){
    struct node*head = create(10);

    printf("\nelements before insertion: \n");
    traversal(head);

    head = insertBeg(head, 1);
    head = insertEnd(head, 80);
    head = insertBtw(head, 40, 1);
    printf("\nelements after insertion: \n");
    traversal(head);

    struct node*h2 = create(20);
    h2 = insertBeg(h2, 15);
    h2 = insertEnd(h2, 60);
    h2 = insertBtw(h2, 70, 1);

    printf("\nlist 2 elements after insertion: \n");
    traversal(h2);

    // printf("\nlists merged: \n");
    // head = merge(head, h2);

    // printf("\nelements after reversal\n");
    // head = reverse(head);

    // head = delBtw(head, 1);
    // printf("\nelements after deletion\n");
    
    printf("\nlists merged in ascending order: \n");
    struct node* merged = sortedMerge(head, h2);
    traversal(merged);

    return 0;
}
