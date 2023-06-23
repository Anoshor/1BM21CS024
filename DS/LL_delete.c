delete_beg(struct node **head) {
    struct node *ptr,*temp;
    if(*head==NULL) {
        printf("List is Empty\n");
    }
    else {
        ptr=*head;
        *head=head->next;
        free(ptr);
    }
}

delete_end(struct node **head) {
    struct node *ptr, *temp;
    if(head==NULL) {
        printf("List is Empty\n");
    }
    else if(head->next==NULL) {
        free(*head);
        head=NULL;
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

delete_specific(struct node **head,int pos) {
    struct node *ptr, *temp;
    if(*head==NULL) {
        printf("List is Empty\n");
    }
    else if(head->next==NULL) {
        free(head);
        *head=NULL;
    }
    else {
        ptr=*head;
        temp=*head;
        for(int i=0;i<pos;i++) {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        free(temp);
    }
}
