#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n; cin>>n; 
    int T; cin>>T; 
    vector<int> a(n);
    for(auto &i : a)
        cin>>i;
    sort(a.begin(), a.end()); 
    for(int i=0;i<n;i++)
    {
        int l=i+1, h=n-1; 
        while(l<h) /* Imp. */
        {
            int sum = a[i] + a[l] + a[h];
            if(sum==T)
            {
                cout<<"True";
                return 0; 
            }
            else if(sum<T)
                l++; 
            else
                h++; 
        }
    }
    cout<<"False"; 
    return 0;
}