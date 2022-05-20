#include <iostream>
#include <vector>

#define MAX 100
using namespace std;

int main()
{
    int t,n;
    int arr[MAX];

    cin>>t;
    while(t--)
    {
        int f=0;
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            cin>>arr[i];
        }

        vector <int> vec;
        for(int i=0 ; i<n ; i++)
        {
            int j=i+1 , k=n-1;

            while(j<n && k>j)
            {
                if(arr[i]+arr[j]==arr[k])
                {
                    vec.push_back(i+1);
                    vec.push_back(j+1);
                    vec.push_back(k+1);
                    break;
                }

                else if(arr[i]+arr[j]>arr[k])
                {
                    j++;
                    k=n-1;
                    // break;
                }

                else
                    {
                        k--;
                    }
            }
            
        }

        if(vec.empty())
        {
            cout<<"No sequence found!";
        }

        else
        {
            for(int i=0 ; i<vec.size() ; i++)
            {
                cout<<vec[i]<<"  ";
            }
            cout<<endl;
        }

    }
}