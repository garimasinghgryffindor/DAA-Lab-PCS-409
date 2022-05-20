#include <iostream>
#define MAX 100

using namespace std;


void mergeSort(int arr[],int lb,int ub);
void merge(int arr[],int lb,int mid,int ub);
int binarySearch(int arr[],int size,int key);
void findPair(int[],int,int);
void print(int arr[],int n);

int main()
{
    int test_cases, n, arr[MAX], key;

    cout<<"Enter the number of test cases:\n";
    cin>>test_cases;

    for(int i = 0 ; i<test_cases ; i++)
    {
        cout<<"Enter the length of the array:\n";
        cin>>n;

        cout<<"Enter the elements:\n";
        for(int j = 0; j<n ; j++)
        {
            cin>>arr[j];
        }

        cout<<"Enter the key:\n";
        cin>>key;

        mergeSort(arr,0,n-1);
        print(arr,n);
        findPair(arr,n,key);
    }

    return 0;
}



void findPair(int arr[],int n,int key)
{
    

    int f=0;

for(int i = 0 ; i<n/2; i++)
    {
        int chk=binarySearch(arr,n,key-arr[i]);

        if(chk!=-1)
        {
            cout<<arr[i]<<" "<<key-arr[i]<<endl;
            f++;
        }
    }

    if(f==0)
    {
        cout<<"No such pair found!\n";
    }
}

int binarySearch(int arr[],int size,int key)
{
    int lb=0, ub=size-1;
    int mid;

    while(lb<=ub)
    {
        mid = (lb + ub)/2;
        if(key == arr[mid])
        {
            return mid;
        }

        if(key > arr[mid])
        {
            lb = mid+1;
        }

        else{
            ub = mid-1;
        }
    }

    return -1;
}

void mergeSort(int arr[],int lb,int ub)
{
    int mid = (lb+ub)/2;
    
    if(lb<ub)
    {
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[],int lb,int mid,int ub)
{
    int n1 = mid-lb+1 , n2 = ub-mid;
    int left[n1], right[n2];
    
    //  Copying left subarray
    for(int i=0 ; i<n1 ; i++)
    {
        left[i] = arr[lb+i];
    }
    
    //  Copying Right subarray
    for(int j=0 ; j<n2 ; j++)
    {
        right[j] = arr[mid+j+1];
    }
    
    int i=0,j=0,k=lb;
    
    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
        {
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    
    while(i<n1)
    {
        arr[k++] = left[i++];
    }
    
    while(j<n2)
    {
        arr[k++] = right[j++];
    }
}

void print(int arr[],int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}



