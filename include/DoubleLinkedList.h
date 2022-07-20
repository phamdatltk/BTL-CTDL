#include<iostream>

template<typename T>
struct node
{
    /* data */
    struct node<T> *next;
    T data;
    struct node<T> *prev;
};

template<typename T>
void insertFront(struct node<T> **head, T data);
template<typename T>
void insertAfter(struct node<T> *prev, T data);
template<typename T>
void insertTail(struct node<T> **head, T data);
template<typename T>
void deleteHead(struct node<T> **head);
template<typename T>
void deleteTail(struct node<T> **head);
template<typename T>
void deleteNode(struct node<T> **head, struct node<T>* del_node);
template<typename T>
void sortedInsert(struct node<T>** head_ref, struct node<T>* newnode);
template<typename T>
void insertionSort(struct node<T>** head_ref);
template<typename T>
void printList(struct node<T>* head);
template<typename T>
void Swap(T &a,T &b);
template<typename T>
void bubbleSort(struct node<T> *start);
template<typename T>
void selectionSort(struct node<T> *start);