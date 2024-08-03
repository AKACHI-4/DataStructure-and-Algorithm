#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)


void Heapify(vi &a, int n, int i)
{

    int MxIdx = i;

    int L = 2*i + 1;
    int R = 2*i + 2;

    if(L<n && a[L]>a[MxIdx])
        MxIdx = L; 
    if(R<n && a[R]>a[MxIdx])
        MxIdx = R; 
    if(MxIdx != i) /* Means if MxIdx replaced with it's child */
    {
        swap(a[i], a[MxIdx]);

        Heapify(a, n, MxIdx);
    }    

}

void HeapSort(vi &a)
{

    int n = a.size();

    /* 1st index of non leaf node -> n/2-1 */
    for(int i=n/2-1;i>=0;i--)
    {
        Heapify(a,n,i);
    } /* convert into MaxHeap */

    for(auto val : a)
        cout<<val<<" "; 
    cout<<endl;

    /* Heapify Down */
    for(int i=n-1;i>0;i--)
    {
        swap(a[0], a[i]);

        Heapify(a,i,0);

    }
    
}

signed main()
{
    
    // int n; cin>>n; 

    // vi a(n);

    // rep(i,0,n)
    //     cin>>a[i];

    vi a = {5,4,1,2,6,3};

    HeapSort(a);

    // rep(i,0,n)
    rep(i,0,6)
        cout<<a[i]<<" ";

    return 0;
}