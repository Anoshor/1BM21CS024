#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 50
int queue[MAX];
int rear=-1;
int front=-1;

int isFull() {
    if(rear==(MAX-1)) {
        return 5;
    } 
    else {
        return 6;
    }
}

int isEmpty() {
    if((front==-1)&&(rear==-1)) {
        return 5;
    }
    else {
        return 6;
    }
}
void display() {
    int i;
    if(front==-1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue is: ");
        for (i=front;i<=rear;i++) {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
    
}

void enqueue(int x) {
    if(isFull()==5) {
        printf("Queue is full\n");
    }
    
    else if(isEmpty()==5) {
        front=rear=0;
        queue[rear]=x;
    }
    else {
        rear=rear+1;
        queue[rear]=x;
    }
}
void dequeue() {
    if(isEmpty()==5) {
        printf("Queue is Empty");
    }
    else if (front==rear) {
        front=rear=-1;
    }
    else {
        front = front + 1;
    }
}

int main() {
    while(1) {
        printf("\n 1. enqueue 2. dequeue 3. display Else: Exit\n");
        int n;
        scanf("%d",&n);
        if(n==1) {
            int x;
            scanf("%d",&x);
            enqueue(x);
        }
        else if(n==2) {
            dequeue();
        }
        else if(n==3){
            display();
        }
        else {
            exit(0);
        }
    }

    return 0;
}
