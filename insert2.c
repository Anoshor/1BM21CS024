#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node() {
    struct node *temp; int data1;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&data1);
    temp->data=data1;
    temp->next=NULL;
    
}

void insert_beg(struct node **head) {
    struct node *ptr;
    ptr=create_node();
    ptr->next=*head;
    *head=ptr;
}

void insert_end(struct node **head) {
    struct node *ptr,*temp;
    ptr=*head;
    while((ptr->next)!=NULL) {
        ptr=ptr->next;
    }
    temp=create_node();
    ptr->next=temp;   
}

void insert_mid(struct node **head,int i) {
    if(i==1) {
        insert_beg(head);
    }
    else {
    struct node *ptr,*temp;
    ptr=*head;
    temp=create_node();
    for(int j=0;j<i-2;j++) {
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    }
}

void display(struct node *head) {
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

void insert_sort(struct node **head,int x) {
    struct node *ptr,*temp;
    ptr=*head;
    do {
        ptr=ptr->next;
    }while((ptr->data)!=(x-1));
}

void main() {
    struct node *head=NULL;
    while(1) {
        printf("\n1.Insert Beg  2.Insert Mid  3.Insert End  4.Display\n");
        int c;
        scanf("%d",&c);
        
        if(c==1) {
            insert_beg(&head);
        }
        else if(c==2) {
            printf("where do u want to add a node?: ");
            int pos;
            scanf("%d",&pos);
            insert_mid(&head,pos);
        }
        else if(c==3) {
            insert_end(&head);
        }
        else if(c==4) {
            display(head);
        }
        else if(c==5) {
            insert_sort(&head,8);
        }
        else {
            exit(0);
        }
        
    }
}
