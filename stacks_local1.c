#include<stdbool.h>  
#include <stdio.h>
#include <stdlib.h>
#define size 10

//int stack[size];
//int top=-1;




int isFull(int* t) {
    //bool m;
    
    if((*t)==size) {
        //m=true;
        return 5;
    }
    else {
        //m=false;
        return 6;
    }
}

int isEmpty(int* t) {
    //bool m;
    
    if((*t)==-1) {
        //m=true;
        return 5;
    }
    else {
        //m=false;
        return 6;
    }
}

void push(int* s, int* t, int x) {
    //int tt=*t;
    if(isFull(t)==5) {
        printf("Stack Overflow\n");
    }
    else {
        s[++(*t)]=x;
    }
}

void pop(int* s, int* t) {
    //int tt=*t;
    if(isEmpty(t)==5) {
        printf("Stack underflow\n");
    }
    else {
        printf("%d\n",s[*t]);
        (*t)--;
    }
}

void display(int* s, int* t) {
    //int tt=*t;
    if(isEmpty(t)==5) {
        printf("\nStack is empty");
    }
    else {
        for(int i=(*t);i>=0;i--) {
            printf("\n%d ",s[i]);
        }
    }
}

int main() {
    int stack[10];
    int top=-1;
    while(1) {
        printf("\n 1. Push 2. Pop 3. Display Else: Exit\n");
        int n;
        scanf("%d",&n);
        if(n==1) {
            int x;
            scanf("%d",&x);
            push(stack, &top, x);
        }
        else if(n==2) {
            pop(stack, &top);
        }
        else if(n==3){
            display(stack, &top);
        }
        else {
            exit(0);
        }
    }

    return 0;
}
