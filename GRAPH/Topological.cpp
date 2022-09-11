#include "bits/stdc++.h"
using namespace std; 

#define vi vector<int> 
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a;i<b;i++)

int32_t main(){
    int n,m; cin>>n>>m;
    /* n->edges, m->vertexes/nodes */
    vvi adjL(m);
    vi inDeg(m,0);
    int x,y; 
    rep(i,0,n){
        cin>>x>>y;
        /* directed graph */
        adjL[x].push_back(y);
        inDeg[y]++; 
    }

    queue<int> q; 
    rep(i,0,m){
        if(inDeg[i]==0)
            q.push(i);
    }
    cout<<q.front()<<endl;
    while(!q.empty()){ 
        int a = q.front(); 
        q.pop(); 
        cout<<a<<" ";
        for(auto it : adjL[a]){
            inDeg[it]--; 
            if(!inDeg[it])
                q.push(it);
        }
    }

    return 0; 
}

/*

Assumed Graph for input

4 5
0 1
1 2
2 3
3 4

*/