#include <iostream>

using namespace std;

void maxFrequencyElement(char[],int);

int main()
{
    int test_cases , n;
    char arr[100];
    
    cout<<"Enter the number of test cases:\n";
    cin>>test_cases;

    for(int i = 0 ; i<test_cases ; i++)
    {
        cout<<"Enter the length of the array:\n";
        cin>>n;
        cout<<"Enter the elements:\n";
        for(int j=0 ; j<n ; j++)
        {
            cin>>arr[j];
        }

        maxFrequencyElement(arr,n);
    }

    return 0;
}

void maxFrequencyElement(char arr[],int n)
{
    int count[26];
    for(int i = 0 ; i<26 ; i++)
    {
        count[i] = 0;
    }

    for(int i = 0 ; i<n ; i++)
    {
        (count[arr[i]-97])++;
    }

    int max=0;
    char maxElement;
    for(int i = 0; i<26 ; i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            maxElement = 97+i;
        }
    }

    if(max==1)
    cout<<"No Duplicates present\n";

    else
    cout<<maxElement<<" - "<<max<<endl;

}


