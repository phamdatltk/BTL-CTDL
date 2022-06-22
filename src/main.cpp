#include<iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main(){

    struct node *head = NULL;
    
    insertFront(&head, 5);
    insertFront(&head, 4);
    // insertFront(&head, 6);
    // insertAfter(head->next, 1);
    // insertTail(&head, 10);

    deleteTail(&head);

    printList(head);

    return 0;
}

