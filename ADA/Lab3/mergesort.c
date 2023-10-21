#include <stdio.h>
#include <stdlib.h>

void merge(int* L, int* R, int* A,int nL, int nR) {
    //printf("a\n");
    //int nL=sizeof(L)/sizeof(L[0]);
    //int nR=sizeof(R)/sizeof(R[0]);
    int i=0;
    int j=0;
    int k=0;
    while((i<nL) && (j<nR)) {
        if(L[i]<=R[j]) {
            A[k]=L[i];
            i=i+1;
        }
        else {
            A[k]=R[j];
            j=j+1;
        }
        k=k+1;
    }
    //Exhaustion cases
    while(i<nL) {
        A[k]=L[i];
        k=k+1;
        i=i+1;
    }
     while(j<nR) {
        A[k]=R[j];
        k=k+1;
        j=j+1;
    }
}

void mergesort(int* a,int n) {
    
    
    if(n==1) {
        return;
    }
    else {
    int mid=n/2;
    //printf("%d",mid);
    int left[mid];
    int right[n-mid];
    for(int i=0;i<mid;i++){
        //printf("c");
        left[i]=a[i];
    }
    for (int j=mid; j<(n); j++) 
    {
        right[j-mid]=a[j];
    }
    //printf("r");
    mergesort(left,sizeof(left)/sizeof(left[0]));
    //printf("b");
    mergesort(right,sizeof(right)/sizeof(right[0]));
    //printf("c");
    merge(left,right,a,sizeof(left)/sizeof(left[0]),sizeof(right)/sizeof(right[0]));
    }
    
}

int main() {
    int arr[9]={5,4,3,2,1,7,8,10,2};
    // int x=sizeof(arr)/sizeof(arr[0]);7
    // printf("%d",x);
    mergesort(arr,sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<9;i++) {
        printf("%d ",arr[i]);
    }

    int arr1[2]={1,3};
    int arr2[2]={2,4};
    int arr3[4];
    //merge(arr1,arr,arr3);
    
}
