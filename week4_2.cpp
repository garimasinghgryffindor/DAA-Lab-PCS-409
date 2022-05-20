#include <iostream>
#define MAX 10
using namespace std;
int comp=0;
int swaps=0;

int partition(int arr[],int l,int r)
{
    int x = rand()%(r-l+1) + l;
    swaps++;
    int temp=arr[r];
    arr[r]=arr[x];
    arr[x]=temp;

    int pivot=arr[r];
    int i=l-1;
    for(int j=l ; j<=r-1 ; j++)
    {
        comp++;
        if(arr[j]<pivot)
        {
            i++;
            //swapping
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            swaps++;
        }
    }
    //swapping
    swaps++;
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return (i+1);
}

void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p = partition(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
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
        quickSort(arr,0,n-1);
        for(int i=0 ; i<n ; i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl<<"Comparisons:  "<<comp<<endl<<"Swaps:  "<<swaps<<endl;
        comp=0,swaps=0;
    }

    return 0;
}