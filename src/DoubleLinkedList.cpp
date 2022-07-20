#include "DoubleLinkedList.h"

template<typename T>
void insertFront(struct node<T> **head, T data){
    struct node<T> *newNode = new node<T>;
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

template<typename T>
void insertAfter(struct node<T> *prev, T data){
    struct node<T>* newNode = new node<T>;
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->prev = prev;
    prev->next = newNode;
}

template<typename T>
void insertTail(struct node<T> **head, T data){
    struct node<T> *newNode = new node<T>;
    newNode->data = data;
    newNode->next = NULL;
    struct node<T> *temp = *head;
    if(*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;    
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

template<typename T>
void deleteHead(struct node<T> **head){
    if(*head == NULL){
        return;
    }
    *head = (*head)->next;
}

template<typename T>
void deleteTail(struct node<T> **head){
    struct node<T>* temp = new node<T> ;
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
}

template<typename T>
void deleteNode(struct node<T> **head, struct node<T>* del_node){
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

template<typename T>
void sortedInsert(struct node<T>** head_ref, struct node<T>* newnode)
{
    struct node<T>* current;
    if (*head_ref == NULL)
        *head_ref = newnode;
 
    else if ((*head_ref)->data >= newnode->data) {
        newnode->next = *head_ref;
        newnode->next->prev = newnode;
        *head_ref = newnode;
    }
 
    else {
        current = *head_ref;
 
        while (current->next != NULL &&
               current->next->data < newnode->data)
            current = current->next;
 
        newnode->next = current->next;
 
        if (current->next != NULL)
            newnode->next->prev = newnode;
 
        current->next = newnode;
        newnode->prev = current;
    }
}

template<typename T>
void insertionSort(struct node<T>** head_ref)
{
    struct node<T>* sorted = NULL;
    struct node<T>* current = *head_ref;
    while (current != NULL) {
        struct node<T>* next = current->next;
        current->prev = current->next = NULL;
 
        sortedInsert(&sorted, current);
 
        current = next;
    }
 
    *head_ref = sorted;
}

template<typename T>
void printList(struct node<T>* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

template<typename T>
void push(struct node<T>** head_ref, T new_data)
{
    struct node<T>* new_node =
         (struct node<T>*)malloc(sizeof(struct node<T>));
 
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
}
 
template<typename T>
void Swap(T &a,T &b){
    T c = a;
    a = b;
    b = c;
}

template<typename T>
void bubbleSort(struct node<T> *start)
{
    T swapped;
    struct node<T> *ptr1;
    struct node<T> *lptr = NULL;
  
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                Swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

template<typename T>
void selectionSort(struct node<T> *start){
    struct node<T> *ptr = start;
    
    if(start = NULL)
        return;
    
    while(ptr->next != NULL){
        struct node<T> *ptr1 = ptr->next;
        while(ptr1->next != NULL){
            if(ptr1->data < ptr->data){
                Swap(ptr1->data, ptr->data);
            }
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}
