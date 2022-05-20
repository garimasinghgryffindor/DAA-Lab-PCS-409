#include <iostream>
#define MAX 100

using namespace std;

int main()
{
    int t,n,key;
    int arr[MAX];
    cin>>t;

    while(t--)
    {
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            cin>>arr[i];
        }
        cin>>key;
        int count=0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                if(arr[i]-arr[j]==key || arr[j]-arr[i]==key)
                {
                    count++;
                }
            }
        }

        cout<<count<<endl;
    }
}