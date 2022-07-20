#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DoubleLinkedList.cpp"
using namespace std;

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

int main(){

    int n = 1000;
    int arr[n];
    srand((int)time(0));
    int r;
    for(int i = 0; i < n; ++i){
        r = random(1,n);
        arr[i] = r;
    }
    struct node<int> *head = NULL;
    for(int i = 0; i < n; ++i){
        insertFront(&head, arr[i]);
    }

    clock_t start, end;
    double time_use;

    start = clock();     
    selectionSort2(head);
    end = clock();
    printList(head);
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    
    cout<<"Thoi gian chay: "<<time_use;
    cout << endl;

    return 0;
}

