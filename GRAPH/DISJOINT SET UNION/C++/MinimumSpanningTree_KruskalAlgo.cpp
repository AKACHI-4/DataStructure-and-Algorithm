#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vvi vector<vi> 

const int N = 1e5+2;
vi parent(N);
vi Size(N);

void make_set(int a){
    parent[a] = a; 
    Size[a] = 1; 
}
int find_set(int a){
    if(a==parent[a]) return a; // means leading node 
    return parent[a] = find_set(parent[a]); // path comparison 
}   
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);
        parent[b] = a; // (*)
        Size[a] += Size[b];
    }
}
signed main(){
    for(int i=0;i<N;i++)
        make_set(i);
    int v, e; cin>>v>>e; 
    vvi edges;
    for(int i=0;i<e;i++){
        int w,u,v; cin>>w>>u>>v;
        edges.push_back({w,u,v});
    }

    // Kruskal's Algorithm 
    sort(edges.begin(),edges.end()); // because we want minimum
    int SpanningTreeCost = 0; 
    for(auto it : edges){
        int w = it[0], u = it[1], v = it[2];
        int a = find_set(u); 
        int b = find_set(v);
        if(a==b) continue; // cycle exist 
        else{ // cycle not exist
        union_set(a,b);
        cout<<u<<" "<<v<<endl;
        SpanningTreeCost += w; 
        }    
    }
    cout<<"SpanningTreeCost : "<<SpanningTreeCost<<endl;

    return 0;
} // Spanning tree is not connected 