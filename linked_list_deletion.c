#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node* next; 
};



void Display(struct Node* head){

    struct Node* ptr;
    ptr = head;

    while (ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
};


struct Node* DeleteFirst(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


void DeleteLast(struct Node* last, struct Node* secondLast){
    
    free(last);
    secondLast->next = NULL;
}

void DeleteIndex(struct Node* head, int index){
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    
}


void DeleteValue(struct Node* head, int value){
    struct Node* p = head;
    struct Node* q = head->next;

    while (q->data != value){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
}

int main(int argc, char const *argv[])
{
    
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;
    // head = DeleteFirst(head);
    // DeleteLast(fifth, fourth);
    
    // DeleteIndex(head, 2);

    DeleteValue(head, 20);
    Display(head);

    return 0;
}