#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second 
#define setBits(x) builtin_popcount(x)

signed main()
{
    int k; cin>>k; 

    vector<vector<int>> a(k);

    rep(i,0,k)
    {
        int size; cin>>size;

        a[i] = vector<int>(size);
        // To Give size each individual array

        rep(j,0,size)
            cin>>a[i][j];
    }

    vector<int> idx(k,0);
    // it means a vector of k size Which each element is zero

    priority_queue<pii,vector<pii>,greater<pii>> pq; // minheap 

    // { first element, array number }

    rep(i,0,k)
        pq.push({a[i][0], i}); 
    // first element of each individual vector in 2D vector getting placed in minheap

    vi ans;

    while(!pq.empty())
    {
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.ff);

        /* most important part */ 
        if(idx[x.ss]+1 < a[x.ss].size())
            pq.push({a[x.ss][idx[x.ss]+1], x.ss});
        idx[x.ss] += 1;
    }

    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}