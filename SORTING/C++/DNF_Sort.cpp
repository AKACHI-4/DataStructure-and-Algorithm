#include<bits/stdc++.h>

using namespace std;

void swap(int a[], int i, int j )
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp; 
}

void DNF_sort(int a[], int n)
{
    int low = 0, mid = 0, high = n-1; 

    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a,low,mid);
            low++, mid++;  
        }
        else if(a[mid]==1)
        {
            mid++; 
        }
        else
        {
            swap(a,mid,high);
            high--; 
        }
    }
    return ; 
}

int main()
{
    int a[] = { 1, 0, 2, 1, 0, 1, 2, 1, 2 };
    
    DNF_sort(a, 9);

    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl; 

    return 0;
}