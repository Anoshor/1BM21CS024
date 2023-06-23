#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

struct node* create_node() {
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node *));
    return ptr;
}

void beginsert() {
    struct node *ptr=create_node();
    int item;
    
    if(ptr==NULL) {
        printf("\nOVERFLOW");
    }
    else {
        printf("\nEnter value: ");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\nSuccessfully inserted Node");
    }
}
void lastinsert() {
    struct node *ptr,*temp;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL) {
        printf("\nOVERFLOW");
    }
    else {
        printf("\nEnter value: ");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL) {
            ptr->next=NULL;
            head=ptr;
            printf("\nNode Inserted");
        }
        else {
            temp=head;
            while((temp->next)!=NULL) {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\nNode Inserted");
        }
    }
}

void display() {
    struct node *ptr;
    ptr=head;
    if(ptr==NULL) {
        printf("\nEmpty Linked List");
    }
    else {
        printf("\nValues: ");
        while(ptr!=NULL) {
            printf(" %d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void main() {
    int choice;
    while(1) {
        printf("\n1. INSERT 2. Display \n");
        scanf("%d",&choice);
        
        if(choice==1) {
            beginsert();
        }
        else if(choice==2) {
            display();
        }
        else {
            exit(0);
        }
        
    }

}
