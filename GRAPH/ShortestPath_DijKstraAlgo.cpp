// used to find shortest path from a vertex
// not applicable for negative cycle means where weight is considered in negative number 

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define pii pair<int,int>
#define vpii vector<pii> 
#define vvpii vector<vpii> 
#define rep(i,a,b) for(int i=a;i<b;i++)

const int INF = 1e5; 

signed main(){
    int v, e; cin>>v>>e; 
    vpii Graph[v+1];
    rep(i,0,e){
        int x,y,w; cin>>x>>y>>w; 
        Graph[x].push_back({y,w});
        Graph[y].push_back({x,w});
    }
    // Distance -> EdgeWeight
    vi Distance(v+1,INF);
    int src; cin>>src; 
    Distance[src] = 0; 
    set<pii> s; 
    // set format -> { weight, source/node }
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : Graph[x.second]){
            if(Distance[it.first] > Distance[x.second] + it.second){
                s.erase({Distance[it.first],it.first});
                Distance[it.first] = Distance[x.second] + it.second;
                s.insert({Distance[it.first],it.first});
            }
        } 
    }
    for(int i=1;i<=v;i++){
        if(Distance[i]<INF)
            cout<<Distance[i]<<" ";
        else 
            cout<<-1<<" "; // unreachable nodes
    }
    return 0;
}