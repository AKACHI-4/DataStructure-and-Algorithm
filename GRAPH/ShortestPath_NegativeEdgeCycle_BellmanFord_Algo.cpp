#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

const int INF = 1e7+2;

signed main(){
    int v, e; cin>>v>>e;
    vvi edges; 
    rep(i,0,e){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    vi distance(v,INF);
    int source; cin>>source; 
    distance[source] = 0; 
    rep(i,0,v-1){
        for(auto e : edges){
            int u,v,w; u = e[0], v = e[1], w = e[2];
            distance[v] = min(distance[v],w + distance[u]);
        }
    }
    for(auto i : distance)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}