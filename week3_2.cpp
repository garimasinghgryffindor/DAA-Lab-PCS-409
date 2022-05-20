#include <iostream>
#define MAX 10
using namespace std;

void selection_sort(int arr[],int n)
{
    int comp=0,swaps=0;
    for(int i=0 ; i<n-1 ; i++)
    {
        int min=i;
        for(int j=i+1 ; j<n ; j++)
        {
            comp++;
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        // if(min!=i)
            {
                int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
                swaps++;
            }
    }

    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<"comparisons:  "<<comp<<endl<<"swaps:  "<<swaps<<endl;
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
        selection_sort(arr,n);
    }

    return 0;
}