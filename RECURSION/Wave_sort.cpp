#include<bits/stdc++.h>

using namespace std;

void swap(int a[], int i, int j)
{
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp ;
}

void wavesort(int arr[], int n)
{
    for(int i=1;i<n;i+=2)
    {
        if( arr[i] > arr[i-1] )
        {
            swap(arr,i,i-1);
        }
        if( arr[i] > arr[i+1] && i<=n-2)
        {
            swap(arr,i,i+1);
        }
    }
}

int main()
{
    int a[] = { 1, 3, 4, 7, 5, 6, 2 };
    
    wavesort(a, 8);

    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
} // TIME COMPLEXTIY : O(n) or O(n/2)