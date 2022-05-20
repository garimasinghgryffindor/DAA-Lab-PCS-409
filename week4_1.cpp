#include <iostream>
#define MAX 10
using namespace std;
int comp=0;

void merge(int arr[],int lb,int mid,int ub)
{
    int n1=mid-lb+1;
    int n2=ub-mid;

    int L[n1],R[n2];
    for(int i=0 ; i<n1 ; i++)
    {
        L[i]=arr[lb+i];
    }
    for(int i=0 ; i<n2 ; i++)
    {
        R[i]=arr[mid+1+i];
    }

    int i=0, j=0, k=lb;
    while(i<n1 && j<n2)
    {
        comp++;
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
        }
    }

    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main()
{
    int t,n;
    int arr[MAX];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            cin>>arr[i];
        }

        mergeSort(arr,0,n-1);
        for(int i=0 ; i<n ; i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
        cout<<"Comparisons:  "<<comp<<endl;
        comp=0;
    }

    return 0;
}