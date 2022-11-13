#include <stdio.h>
#include <ctype.h>

#define size 50

char stack[size];
int top=-1;

push (char elem) {   
    stack[++top]=elem;
}
char pop() {
    return (stack[top--]);
}
int pr (char symbol) {
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
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("Enter Infix Expression: ");
    scanf("%s",infix);
    push('#');

    while((ch=infix[i++])!='\0') { //understand well
        if(ch=='(') {
            push(ch);
        }
        else {
            if(isalnum(ch)) {
                postfix[k++]=ch;
            }
            else {
                if(ch==')') {
                    while(stack[top]!='(') {
                        postfix[k++]=pop();
                    }
                    elem=pop(); //to remove the '(' from stack
                }
                else {
                    while(pr(stack[top])>=pr(ch)) {
                        postfix[k++]=pop();
                    }
                    push(ch); //push AFTER the above lines remove the rest
                }
            }
        }
    }
    while(stack[top]!='#') {
        postfix[k++]=pop(); //add the rest
    }
    postfix[k]='\0'; //make it a proper string
    printf("\nPostfix Expression = %s\n",postfix);
}