#include<bits/stdc++.h>
using namespace std; 

#define vi vector<int>
#define vvi vector<vi> 
#define pii pair<int,int>
#define vii vector<pair> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

const int N = 1e5+2;

// vi adjL[N];
/* a 2D Vector having fixed size */

signed main(){
    int n, m;
    cin>>n>>m; 
    /* n->no. of edges, m->no. of nodes */
    vvi adjM(n+1,vi(n+1,0)); 
    /* adjM -> An Adjacent matrix (2D-vector) having size of n+1 and each included 1D vector have size n+1 with each element zero(0) */
    int x, y; 
    rep(i,0,m)
    {
        cin>>x>>y; 
        /* assuming Undirected List */
        adjM[x][y] = 1;
        adjM[y][x] = 1; 
    }

    cout<<"Adjacent Matrix of Given Graph : "<<endl;
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
            cout<<adjM[i][j]<<" ";
        cout<<endl; 
    }

    cout<<endl<<endl; 

    cin>>n>>m; 

    vi adjL[m+1];
    /* a 2D Vector having fixed size also in terms of individual vector */

    rep(i,0,m)
    {
        cin>>x>>y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    cout<<"Adjacent List of Given Graph : "<<endl;
    rep(i,1,n+1)
    {
        cout<<i<<" -> ";
        vi :: iterator it; 
        for(it=adjL[i].begin();it!=adjL[i].end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }

    cout<<endl; 
    return 0;
}