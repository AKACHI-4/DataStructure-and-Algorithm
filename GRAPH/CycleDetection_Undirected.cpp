#include<bits/stdc++.h> 
using namespace std; 

#define vi vector<int> 
#define vb vector<bool> 
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a;i<b;i++)

bool IsCycle(int child, vvi &adj, vb &check, int parent){
    check[child] = true;
    for(auto i : adj[child]){
        if(i!=parent){
            /* if node is already visited */
            if(check[i])
                return true;
            /* if node is not visited so visit using IsCycle */
            if(!check[i] and IsCycle(i,adj,check,child))
                return true;
        }
    }
    return false;
}
signed main(){  
    int n, m; cin>>n>>m; 
    /* n->edges, m->vertics */
    vvi adjL(m);
    int x, y;
    rep(i,0,n){
        cin>>x>>y; 
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }
    bool cycle = false;   
    vb check(m,false);
    rep(i,0,m){
        /* if node is not visited so visit that node using IsCycle */
        if(!check[i] && IsCycle(i,adjL,check,-1))
            cycle = true;
    }
    if(cycle)
        cout<<"Cycle is present!!";
    else
        cout<<"Cycle is not Present!!";
    return 0; 
}

/*

Assummed graph for input 

-> undirected Acyclic
4 5
0 1
1 2
2 3
3 4

-> undirected Cyclic
3 4
0 1
1 2
2 0

*/