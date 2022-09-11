#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n; 
    int k; cin>>k; 
    vector<int> a(n);
    for(auto &i : a)
        cin>>i; 
    int Zerocnt = 0, i = 0, ans = 0; 
    for(int j=0;j<n;j++)
    {
        if(a[j]==0)
            Zerocnt++;
        while(Zerocnt>k)
        {
            if(a[i]==0)
                Zerocnt--;
            i++; 
        }
        // now Zerocount <= k
        ans = max(ans, j-i+1);
    }
    cout<<ans<<endl; 
    return 0;
}