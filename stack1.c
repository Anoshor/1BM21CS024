#include<stdbool.h>  
#include <stdio.h>
#include <stdlib.h>
#define size 10

int stack[size];
int top=-1;




int isFull() {
    //bool m;
    if(top==size) {
        //m=true;
        return 5;
    }
    else {
        //m=false;
        return 6;
    }
}

int isEmpty() {
    //bool m;
    if(top==-1) {
        //m=true;
        return 5;
    }
    else {
        //m=false;
        return 6;
    }
}

void push(int x) {
    if(isFull==5) {
        printf("Stack Overflow\n");
    }
    else {
        stack[++top]=x;
    }
}

void pop() {
    if(isEmpty==5) {
        printf("Stack underflow\n");
    }
    else {
        printf("%d\n",stack[top]);
        top--;
    }
}

void display() {
    if(isEmpty==5) {
        printf("\nStack is empty");
    }
    else {
        for(int i=top;i>=0;i--) {
            printf("\n%d ",stack[i]);
        }
    }
}

int main() {
    while(1) {
        printf("\n 1. Push 2. Pop 3. Display Else: Exit\n");
        int n;
        scanf("%d",&n);
        if(n==1) {
            int x;
            scanf("%d",&x);
            push(x);
        }
        else if(n==2) {
            pop();
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
