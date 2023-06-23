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

void delete_beg(struct node **head) {
    struct node *ptr,*temp;
    if(*head==NULL) {
        printf("List is Empty\n");
    }
    else {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}

void delete_end(struct node **head) {
    struct node *ptr, *temp;
    if(*head==NULL) {
        printf("List is Empty\n");
    }
    else if((*head)->next==NULL) {
        free(*head);
        *head=NULL;
    }
    else {
        ptr=*head;
        temp=*head;
        while((temp->next)!=NULL) {
            ptr=temp;
            temp=temp->next;
        }
        free(temp);
        ptr->next=NULL;
    }
}

void delete_specific(struct node **head,int pos) {
    struct node *ptr, *temp;
    if(*head==NULL) {
        printf("List is Empty\n");
    }
    else if((*head)->next==NULL) {
        free(*head);
        *head=NULL;
    }
    else {
        ptr=*head;
        temp=*head;
        for(int i=0;i<pos-1;i++) {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        free(temp);
    }
}

void search(struct node **head) {
    struct node *ptr;
    int item,i=0,flag=0;
    ptr=*head;
    if(ptr==NULL) {
        printf("\nEmpty List");
    }
    else {
        printf("\nEnter item you want to search: ");
        scanf("%d",&item);
        while(ptr!=NULL) {
            if(ptr->data==item) {
                printf("item found at location %d",i+1);
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==0) {
            printf("item not found\n");
        }
    }
}

void reverse(struct node **head)
{
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;
    while (current != NULL) {
        
        next = current->next;
 
        
        current->next = prev;
 
        
        prev = current;
        current = next;
    }
    *head = prev;
}

void swap(struct node *a, struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void bubblesort(struct node **head) 
{ 
    int swapped, i; 
    struct node *temp; 
    struct node *ptr = NULL; 
  
    
    if (*head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        temp = *head; 
  
        while (temp->next != ptr) 
        { 
            if (temp->data > temp->next->data) 
            { 
                swap(temp, temp->next); 
                swapped = 1; 
            } 
            temp = temp->next; 
        } 
        ptr = temp; 
    } 
    while (swapped); 
} 

int count(struct node **head) {
    struct node *temp=*head;
    int count=0;
    while(temp!=NULL) {
        temp=temp->next;
        count++;
    }
    
    return count;
}

// void bubbleSort(struct node **head)
// {
//     int i, j;
//     int n=count(*head);
//     for (i = 0; i < n - 1; i++)
 
        
//         for (j = 0; j < n - i - 1; j++)
//             if (ptr > ptr)
//                 swap(&arr[j], &arr[j + 1]);
// }

struct node *concat (struct node **head1,struct node **head2) {
    struct node *ptr;
    if(*head1==NULL) {
        *head1=*head2;
        return *head1;
    }
    if(*head2==NULL) {
        return *head1;
    }
    ptr=*head1;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }
    ptr->next=*head2;
    return *head1;
}
void main() {
    struct node *head=NULL;
    struct node *head2=NULL;
    while(1) {
        printf("\n1.Insert Beg  2.Insert Mid  3.Insert End  4.Display 5.Delete Beg 6.Delete End 7.Delete Specific 8.Search 9. Reverse 10. Sort\n");
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
            delete_beg(&head);
        }
        else if(c==6) {
            delete_end(&head);
        }
        else if(c==7) {
            printf("where do u want to delete a node?: ");
            int pos1;
            scanf("%d",&pos1);
            delete_specific(&head,pos1);
        }
        else if(c==8) {
            search(&head);
        }
        else if(c==9) {
            reverse(&head);
        }
        else if(c==10) {
            bubblesort(&head);
        }
        
        else {
            break;
        }
        
    }
    while(1) {
        printf("\n1.Insert Beg  2.Insert Mid  3.Insert End  4.Exit\n");
        int c;
        scanf("%d",&c);
        
        if(c==1) {
            insert_beg(&head2);
        }
        else if(c==2) {
            printf("where do u want to add a node?: ");
            int pos;
            scanf("%d",&pos);
            insert_mid(&head2,pos);
        }
        else if(c==3) {
            insert_end(&head2);
        }
        else {
            break;
        }
    }
    
    head=concat(&head,&head2);
    display(head);
    
}
