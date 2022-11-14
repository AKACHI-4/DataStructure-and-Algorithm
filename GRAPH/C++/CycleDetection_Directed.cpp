#include "bits/stdc++.h"
using namespace std;

bool IsCycle(int src, vector<bool> &visit, vector<vector<int>> &adjL, vector<int> &stack){
    stack[src] = 1;
    if(!visit[src]){
        visit[src] = true;
        for(auto i : adjL[src]){
            if(!visit[i] and IsCycle(i,visit,adjL,stack))
                return true;
            if(stack[i])
                return true;
        }
    }
    stack[src] = 0; 
    return false;
}
signed main(){
    int n, m; cin>>n>>m;
    /* n->edges, m->vertices */
    vector<vector<int>> adjL(m);
    for(int i=0;i<n;i++){
        int x, y; cin>>x>>y; 
        adjL[x].push_back(y);
    }
    bool flag = false; 
    vector<int> stack(m,0);
    vector<bool> visit(m,false);
    for(int i=0;i<n;i++){
        if(!visit[i] && IsCycle(i,visit,adjL,stack))
            flag = true;    
    }
    if(flag)
        cout<<"Cycle is Present!!"<<endl; 
    else   
        cout<<"Cycle is not Present!!"<<endl;
    return 0;
}