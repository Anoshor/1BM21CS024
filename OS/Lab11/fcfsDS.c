#include<stdio.h>
#include<stdlib.h>
void main()
{
    int tr,n,total=0,curr;
    printf("Enter the total no of tracks in the disk:\n");
    scanf("%d",&tr);
    printf("Enter the number of requests in the request queue:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the request sequence:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the current head positon of the disk arm:\n");
    scanf("%d",&curr);
    int diff[n];

    for(int i=0;i<n;i++)
    {
        total+=abs(arr[i]-curr);
        diff[i] = abs(arr[i]-curr);
        curr=arr[i];
    }
    printf("\nTracks Traversed\t\tDifference:\n");
    for(int i = 0; i<n; i++) {
        printf("%d\t\t\t\t%d\n",arr[i], diff[i]);
    }
    printf("The total head movements are using FCFS scheduling:%d\n",total);
    float avgMovement = total/n;

    printf("Average Header movement :%.2f\n",avgMovement);
}
