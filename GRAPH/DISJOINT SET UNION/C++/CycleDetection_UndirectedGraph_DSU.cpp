#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vvi vector<vi> 

const int N = 1e5+6;
vi parent(N);
vi Size(N);

// DSU start
void make_set(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find_set(int v){
    if(v==parent[v]) return v; 
    return parent[v] = find_set0(parent[v]); // path comparison 
}// return parent/leading node which represent whether it is in same set or not 

// union by size/rank
void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u!=v){
        if(Size[u]<Size[v])
            swap(u,v);
        parent[v] = u; 
        Size[u] += Size[v];
    }
} // size of set u will always will be bigger if not so swap (*just to reduce conditions)
// DSU end


int main(){
    for(int i=0;i<N;i++)
        make_set(i);
    int n, m; cin>>n>>m; // n->nodes, m->edges 
    vvi edges; 
    for(int i=0;i<m;i++){
        int x, y; cin>>x>>y; 
        edges.push_back({x,y});
    }
    bool cycle = false;
    for(auto it : edges){
        int x = it[0], y = it[1];
        x = find_set(x);
        y = find_set(y);       
        if(x==y)
            cycle = true; 
        else 
            union_set(x,y);
    }
    if(cycle) cout<<"Cycle is present"<<endl;
    else cout<<"cycle is not present"<<endl; 
    return 0;
}