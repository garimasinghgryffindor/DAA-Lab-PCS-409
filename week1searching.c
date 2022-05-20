//  Week 1 Question 1

#include <stdio.h>
#define MAX 100

void search(int[],int,int);

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
        search(arr,size,key);
    }

    return 0;
}


void search(int arr[],int N,int key)
{
    int f=0, i, count=0;
    for(i=0 ; i<N ; i++)
    {
        count++;
        if(arr[i]==key)
        {
            printf("Present %d\n",count);
            f=1;
            break;
        }
    }

    if(f==0)
    printf("Not Present %d\n",count);
}

