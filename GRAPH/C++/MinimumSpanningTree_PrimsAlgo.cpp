// #include<bits/stdc++.h>
// using namespace std;

// #define vi vector<int> 
// #define vvi vector<vi> 

// const int N = 1e5+2;
// vi parent(N);
// vi Size(N);

// void make_set(int a){
//     parent[a] = a; 
//     Size[a] = 1; 
// }
// int find_set(int a){
//     if(a==parent[a]) return a; // means leading node 
//     return parent[a] = find_set(parent[a]); // path comparison 
// }   
// void union_set(int a, int b){
//     a = find_set(a);
//     b = find_set(b);
//     if(a!=b){
//         if(Size[a]<Size[b]) swap(a,b);
//         parent[b] = a; // (*)
//         Size[a] += Size[b];
//     }
// }
// signed main(){
//     for(int i=0;i<N;i++)
//         make_set(i);
//     int v, e; cin>>v>>e; 
//     vvi edges;
//     for(int i=0;i<e;i++){
//         int w,u,v; cin>>w>>u>>v;
//         edges.push_back({w,u,v});
//     }

//     // Kruskal's Algorithm 
//     sort(edges.begin(),edges.end()); // because we want minimum
//     int SpanningTreeCost = 0; 
//     for(auto it : edges){
//         int w = it[0], u = it[1], v = it[2];
//         int a = find_set(u); 
//         int b = find_set(v);
//         if(a==b) continue; // cycle exist 
//         else{ // cycle not exist
//         union_set(a,b);
//         cout<<u<<" "<<v<<endl;
//         SpanningTreeCost += w; 
//         }    
//     }
//     cout<<"SpanningTreeCost : "<<SpanningTreeCost<<endl;

//     return 0;
// } // Spanning tree is not connected 



#include<bits/stdc++.h>
using namespace std; 

#define vi vector<int>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a; i<b; i++)

vvi edges;
vi parent, rank;
int v, e;

class DSU{
    vi parent;
    vi size, rank; 

    public : 

    DSU(int n){
        parent.resize(n); 
        rank = vi(n,0); 
        size = vi(n);
        makeSet(n); 
    }

    void makeSet(int n) {
        for(int i=0; i<n; i++)
            parent[i] = i; 
    }

    int findPar(int a) {
        if(parent[a]==a) return parent[a]; 
        return parent[a] = findPar(parent[a]); 
    }

    bool unionRank(int a, int b) { 
        a = findPar(a); 
        b = findPar(b); 

        if(a == b)
            return false ; 

        if (rank[a] >= rank[b]) {
            parent[b] = a; 
            rank[a]++; 
        } else { 
            parent[a] = b; 
            rank[b]++; 
        }
        
        return true ;
    }

    bool unionSize(int a, int b) {
        a = findPar(a); 
        b = findPar(b); 

        if(a == b)
            return false ; 

        if (size[a] >= size[b]) {
            parent[b] = a; 
            size[a] += size[b]; 
        } else { 
            parent[a] = b; 
            size[b] += size[a]; 
        }
        
        return true ;
    }

};

int kruskal(int src) {

    int n = edges.size(); 
    DSU* dsu = new DSU(n); 

    int cost = 0; 

    for(int i=0; i<e; i++) {
        int a = edges[i][1]; 
        int b = edges[i][2]; 

        if(dsu->unionSize(a,b))
            cost += edges[i][0]; 
    }

    return cost; 
}

signed main() { 

    cin>>v>>e; 
    rep(i,0,e) {
        int w,u,v; cin>>u>>v>>w; 
        edges.push_back({w,u,v});   
    }

    sort(edges.begin(), edges.end()); 
    cout<<"Minimum Spanning tree cost is : "<<kruskal(0)<<endl;
    
    return 0; 
}