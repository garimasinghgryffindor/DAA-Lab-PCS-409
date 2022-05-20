//  Week 1 Question 2

#include <stdio.h>

#define MAX 100

void search(int[],int,int,int,int);

int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0)
    {
        int size, i, key;
        int arr[MAX];
        scanf("%d",&size);
        for(i=0 ; i<size ; i++)
        {
            scanf("%d",&arr[i]);
        }
        scanf("%d",&key);
        search(arr,0,size-1,key,0);
    }

    return 0;
}

void search(int arr[],int lb,int ub,int key,int count)
{
    if(lb<=ub)
    {
        int mid = (lb+ub)/2;
        count++;
        if(arr[mid]==key)
        {
            printf("Present %d\n",count);
            return;
        }

        else if(arr[mid]<key)
        {
            search(arr,mid+1,ub,key,count);
        }
        else
        {
            search(arr,lb,mid-1,key,count);
        }
    }

    else
    printf("Not Present %d\n",count);
}