#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vb vector<bool> 
#define rep(i,a,b) for(int i=a;i<b;i++)

bool Bipartite = true;
void Color(int node, int clr, vb &visited, vi &color, vi adjL[]){
    // similar as base condition 
    if(color[node]!=-1 and color[node]!=clr){
        /*
            1. node is not colored it means either it will be red(0) in color or blue(1) in color 
            2. if we want to color that node as red(0) so it is already colored as blue(1) or vise-versa 
        */
        // means that one node is already colored with differenent color 
        Bipartite = false;
        return; 
    }
    if(visited[node])
        return; 
    color[node] = clr; 
    visited[node] = true; 
    for(auto it : adjL[node]){
        // 1 xor 1 -> 0 
        // 0 xor 1 -> 1
        Color(it,clr xor 1,visited,color,adjL); // Recursive call 
    }
}
signed main(){
    int n, m; cin>>n>>m; 
    // n->edges m->nodes
    vi adjL[m];
    vb visited(m,false);
    vi color(m,-1);
    // 1->blue 
    // 0->red 
    // (-1)->uncolored
    rep(i,0,n){
        int u, v; cin>>u>>v; 
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    rep(i,0,m){
        if(!visited[i])
            Color(i,0,visited,color,adjL);
    }
    if(Bipartite) cout<<"Graph is Bipartite"<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    else cout<<"Graph is not Bipartite"<<endl;
    return 0;
}