#include<iostream>

struct node
{
    /* data */
    struct node *next;
    int data;
    struct node *prev;
};

void insertFront(struct node **head, int data){
    struct node *newNode = new node;
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

void insertAfter(struct node *prev, int data){
    struct node* newNode = new node;
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->prev = prev;
    prev->next = newNode;
}


void insertTail(struct node **head, int data){
    struct node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    struct node *temp = *head;
    if(*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;    
    }
    while (temp->next != NULL)
    {
        /* code */
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void displayList(struct node *node){

    while (node != NULL)
    {
        /* code */
        printf("%d -> ", node->data);
        node = node->next; 
    }
    if(node == NULL)
        printf("NULL\n"); ;
}

void deleteHead(struct node **head){
    if(*head == NULL){
        return;
    }
    *head = (*head)->next;
}

void deleteTail(struct node **head){
    struct node* temp = new node ;
    temp = *head;
    while (temp->next != NULL)
    {
        /* code */
        temp = temp->next;
    }
    temp->prev->next = temp->next;
}

void deleteNode(struct node **head, struct node* del_node){
    if(*head == NULL || del_node == NULL){
        return;
    }
    if(*head == del_node){
        *head  = del_node->next;
    }
    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;
    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;
    free(del_node);
}

void insertionSoft(struct node **head){
    struct node *i = (*head)->next;
    while(i->next != NULL){
        
        struct node *temp = i;
        struct node *j = temp->prev;
        while(temp->data <= j->data){
            j->next = j;
            if(j->prev != NULL)
                j = j->prev;
                
        }

        i = i->next;
    }
}