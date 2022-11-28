

void insert_right() {
    int val;
    printf("\nEnter the value to be added: ");
    scanf("%d",&val);
    if((left==0 && right == MAX-1)) {
        printf("\nOVERFLOW");
    }
    if(left==-1) {
        left=0;
        right=0;
    }
    else {
        if(right=MAX-1)
            right=0;
        else
            right=right+1;
    }
    de_queue[right]=val;
}

void insert_left() {
    int val;
    printf("\nEnter the value to be added: ");
    scanf("%d",&val);
    if((left==0 && right == MAX-1)) {
        printf("\nOVERFLOW");
    }
    if(left==-1) {
        left=0;
        right=0;
    }
    else {
        if(left==0)
            left=MAX-1;
        else
            left=left-1;
    }
    de_queue[left]=val;
}

void delete_right() {
    if(left==-1) {
        printf("\nUNDERFLOW");
        return;
    }
    printf("\nThe deleted element is %d\n",de_queue[right]);
    if(left==right) {
        left=-1;
        right=-1;
    }
    else {
        if(right==0)
            right=MAX-1;
        else
            right=right-1;
    }
}

void delete_left() {
    if(left==-1) {
        printf("\nUNDERFLOW");
        return;
    }
    printf("\nThe deleted element is %d\n",de_queue[right]);
    if(left==right) {
        left=-1;
        right=-1;
    }
    else {
        if(left==MAX-1)
            left=0;
        else
            left=left+1;
    }
}