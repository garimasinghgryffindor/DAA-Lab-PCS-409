#include <iostream>
#define MAX 100
using namespace std;

void findDuplicates(int arr[],int n)
{
    int f=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[i]==arr[j])
            {
                cout<<"YES"<<endl;
                f=1;
                break;
            }
        }
        if(f==1)
            break;
    }

    if(f==0)
        cout<<"NO"<<endl;
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
        findDuplicates(arr,n);
    }

    return 0;
}