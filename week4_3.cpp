#include <iostream>
#define MAX 100
using namespace std;

int partition(int arr[],int l,int r)
{
    int pivot = arr[r];
    int i=l-1;
    for(int j=l ; j<=r-1 ; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return i+1;
}

int smallest(int arr[],int l,int r,int k)
{
    if(l==r)
        return arr[l];
    if(l<r)
    {
        int p = partition(arr,l,r);
        int count=p-l+1;
        if(count==k)
            return arr[p];
        else if(count>k)
            return smallest(arr,l,p-1,k);
        else
            return smallest(arr,p+1,r,k);
    }
}

int main()
{   
    int t,n,k;
    int arr[MAX];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        int min=smallest(arr,0,n-1,k);
        cout<<min<<endl;
    }

    return 0;
}