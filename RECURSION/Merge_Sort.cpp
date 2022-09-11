#include<bits/stdc++.h>

using namespace std;

void merge(int ar[], int l, int mid, int r)
{
    int n1 = mid-l+1; // size
    int n2 = r-mid; // size

    int a[n1], b[n2]; // temp arrays

    for(int i=0;i<n1;i++)
    {
        a[i] = ar[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i] = ar[mid+1+i];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    { 
        if(a[i]<b[j])
        {
            ar[k] = a[i];
            k++; i++;    
        }
        else
        {
            ar[k] = b[j];
            k++; j++; 
        }
    }

    while(i<n1)
    {
        ar[k] = a[i];
        k++; i++; 
    }
    while(j<n2)
    {
        ar[k] = b[j];
        k++; j++; 
    }

}

void mergesort(int a[], int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, r);

        merge(a,l,mid,r);
    }
}

int main()
{
    int a[] = { 6, 3, 9, 5, 2, 8, 7, 1 };
    mergesort(a,0,7);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl; 
    return 0;
}

// #define vi vector<int> 

// void merge(vi &arr, int st, int mid, int en){
//     int l1 = mid+1;
//     int l2 = en+1;
//     vi ans((en-st)+1);
//     int i=st,j=mid+1, k=0;
//     while(i<l1 && j<l2){
//         if(arr[i]<arr[j])
//             ans[k++] = arr[i++];
//         else
//             ans[k++] = arr[j++];
//     }
//     while(j<l2)
//         ans[k++] = arr[j++];
//     while(i<l1)
//         ans[k++] = arr[i++];
//     for(i=0;i<k;i++)
//         arr[st+i] = ans[i];
// }
// void MergeSort(vi &a, int st, int en){
//     if(st>=en) return;
//     int mid = st + (en-st)/2;
//     MergeSort(a,st,mid);
//     MergeSort(a,mid+1,en);
//     merge(a,st,mid,en);   
// }
// void mergeSort(vi &arr, int n) {
//     MergeSort(arr,0,n-1);
// }
// int main(){
//     vi arr = {4,3,1,6,7,5,2};
//     mergeSort(arr,7);
//     for(auto i : arr)
//         cout<<i<<" ";
//     return 0; 
// }