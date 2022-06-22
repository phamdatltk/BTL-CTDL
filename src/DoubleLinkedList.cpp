#include "DoubleLinkedList.h"

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

void sortedInsert(struct node** head_ref, struct node* newnode)
{
    struct node* current;
 
    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newnode;
 
    // if the node is to be inserted at the beginning
    // of the doubly linked list
    else if ((*head_ref)->data >= newnode->data) {
        newnode->next = *head_ref;
        newnode->next->prev = newnode;
        *head_ref = newnode;
    }
 
    else {
        current = *head_ref;
 
        // locate the node after which the new node
        // is to be inserted
        while (current->next != NULL &&
               current->next->data < newnode->data)
            current = current->next;
 
        /*Make the appropriate links */
 
        newnode->next = current->next;
 
        // if the new node is not inserted
        // at the end of the list
        if (current->next != NULL)
            newnode->next->prev = newnode;
 
        current->next = newnode;
        newnode->prev = current;
    }
}

// function to sort a doubly linked list using insertion sort
void insertionSort(struct node** head_ref)
{
    // Initialize 'sorted' - a sorted doubly linked list
    struct node* sorted = NULL;
 
    // Traverse the given doubly linked list and
    // insert every node to 'sorted'
    struct node* current = *head_ref;
    while (current != NULL) {
 
        // Store next for next iteration
        struct node* next = current->next;
 
        // removing all the links so as to create 'current'
        // as a new node for insertion
        current->prev = current->next = NULL;
 
        // insert current in 'sorted' doubly linked list
        sortedInsert(&sorted, current);
 
        // Update current
        current = next;
    }
 
    // Update head_ref to point to sorted doubly linked list
    *head_ref = sorted;
}

// function to print the doubly linked list
void printList(struct node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// function to insert a node at the beginning of
// the doubly linked list
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
         (struct node*)malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data = new_data;
 
    /* Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 