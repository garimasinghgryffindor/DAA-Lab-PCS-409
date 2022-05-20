#include <iostream>
#include <cmath>

using namespace std;

void jump(int arr[], int n, int key) {
    int start = 0, comp = 0, flag = 0;
    int end = sqrt(n);
    int i=0;
    while(i<n)
    {
        int next;
        if(i==0)
        {
            next=2;
        }
        else
        {
            next*=2;
            if(next>=n)
            next=n-1;
        }
        
        comp++;
        if(arr[i]==key)
        {
            flag=1;
            break;
        }

        else if(key>arr[i] && key<arr[next])
        {
            for(int j=i+1 ; j<next ; j++)
            {
                comp++;
                if(arr[j]==key)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            break;
        }

        i=next;
    }
    if(flag) cout<<"Present "<<comp<<endl;
    else cout<<"Not present "<<comp<<endl;  
}

int main() 
{
    int n;
    cin>>n;
    while(n--) 
    {
        int size;
        cin>>size;
        int arr[size];
        for(int i = 0; i < size; i++) cin>>arr[i];
        int key;
        cin>>key;
        jump(arr, size, key);
    }
    return 0;
}