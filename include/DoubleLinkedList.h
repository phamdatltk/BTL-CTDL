#include<iostream>

struct node
{
    /* data */
    struct node *next;
    int data;
    struct node *prev;
};

void insertFront(struct node **head, int data);
void insertAfter(struct node *prev, int data);
void insertTail(struct node **head, int data);
void deleteHead(struct node **head);
void deleteTail(struct node **head);
void deleteNode(struct node **head, struct node* del_node);
void insertionSort(struct node **head);
void sortedInsert(struct node** head_ref, struct node* newnode);

// function to sort a doubly linked list using insertion sort
void insertionSort(struct node** head_ref);

// function to print the doubly linked list
void printList(struct node* head);

void swap(int &a,int &b);
void bubbleSort(struct node *start);