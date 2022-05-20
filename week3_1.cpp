#include <iostream>
#define MAX 100

using namespace std;

void insertion_sort(int arr[],int n)
{
    int comp=0,shifts=0;

    for(int i=1 ; i<n ; i++)
    {
        int temp=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            comp++;
            arr[j+1] = arr[j];
            shifts++;
            j--;
        }
        arr[j+1]=temp;
        shifts++;
    }

    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<"comparisons:  "<<comp<<endl<<"shifts:  "<<shifts<<endl;
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
        insertion_sort(arr,n);
    }

    return 0;
}