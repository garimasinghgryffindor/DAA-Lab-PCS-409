//  Week 1 Question 2

#include <stdio.h>
#include <math.h>

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

void search(int arr[], int n, int key)
{
    int i , count=0 , k=1;
    for(i=0 ; i<n ; i*=2)
    {
        count++;

        if(arr[i]==key)
        {
            printf("Present %d\n",count);
            return;
        }
        else
        {
            int x = pow(2,k);
            if(key>arr[i] && key<arr[x])
            {
                int j;
                for(j=i+1 ; j<x ; j++)
                {
                    count++;

                    if(arr[j]==key)
                    {
                        printf("Present %d\n",count);
                        return;
                    }
                }
            }

        }

        if(i==0)
        {
            i++;
        }
    }

    printf("Not Present %d\n",count);
}



