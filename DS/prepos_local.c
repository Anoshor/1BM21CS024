#include <stdio.h>
#include <ctype.h>

#define size 50

//char stack[size];
//int top=-1;

void push (char* stack,int* top,char elem) {   
    stack[++(*top)]=elem;
}
char pop(char* stack,int* top) {
    return (stack[(*top)--]);
}
int precedence (char symbol) {
    if(symbol=='^') {
        return(3);
    }
    else if((symbol=='*')||(symbol=='/')) {
        return(2);
    }
    else if((symbol=='+')||(symbol=='-')) {
        return(1);
    }
    else {
        return(0);
    }
}

void main() {
    char stack[size];
    int top=-1;
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("Enter Infix Expression: ");
    scanf("%s",infix);
    //char hh='#';
    push(stack,&top,'#');

    while((ch=infix[i++])!='\0') { //understand well
        if(ch=='(') {
            push(stack,&top,ch);
        }
        else {
            if(isalnum(ch)) {
                postfix[k++]=ch;
            }
            else {
                if(ch==')') {
                    while(stack[top]!='(') {
                        postfix[k++]=pop(stack,&top);
                    }
                    elem=pop(stack,&top); //to remove the '(' from stack
                }
                else {
                    while(precedence(stack[top])>=precedence(ch)) {
                        postfix[k++]=pop(stack,&top);
                    }
                    push(stack,&top,ch); //push AFTER the above lines remove the rest
                }
            }
        }
    }
    while(stack[top]!='#') {
        postfix[k++]=pop(stack,&top); //add the rest
    }
    postfix[k]='\0'; //make it a proper string
    printf("\nPostfix Expression = %s\n",postfix);
}
