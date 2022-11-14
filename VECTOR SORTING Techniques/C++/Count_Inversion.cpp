#include<bits/stdc++.h>

using namespace std;

long long merge(int a[], int l, int mid, int r)
{
    long long inv = 0; 
    int n1 = mid-l+1; 
    int n2 = r-mid; 

    int a1[n1];
    int a2[n2]; 

    for(int i=0;i<n1;i++)
    {
        a1[i] = a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i] = a[mid+1+i];
    }

    int i=0, j=0, k=l; 
    /*
    i pointer for left array while j pointer is for 
    right array (*not merged now )
    
    k is a iterator in merged array 
    */
    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j])
        {
            a[k] = a1[i];
            i++; k++; 
        }
        else
        {
            a[k] = a2[j];
            
            /*
            Here we have inversion bcz a1[i] > a2[j] and i<j

            if(a1[i] > a2[j])
            so a1[i],a1[i+1],a1[i+2],....a1[] > a2[j] and i<j
            */
            
            inv += n1-i;  /* Most Important */
            j++; k++; 
        }
    }

    while(i<n1)
    {
        a[k] = a1[i];
        k++, i++; 
    }

    while(j<n2)
    {
        a[k] = a2[j];
        k++, j++; 
    }
    return inv; 
}

long long mergesort(int a[], int l, int r)
{
    long long inv = 0 ; 
    if(l<r)
    {
        int mid = ( l + r )/2;
        inv += mergesort(a, l, mid);
        inv += mergesort(a, mid+1, r); 
    
        inv += merge(a, l, mid, r);
    }

    return inv; 
}

int main()
{
    // int a[] = { 3, 5, 6, 9, 1, 2, 7, 8 }; 
    int a[] = { 2, 4, 1, 3, 5 }; 
    cout<<mergesort(a, 0, 5);
    return 0;
}