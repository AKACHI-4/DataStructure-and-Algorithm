// used to find shortest path from a vertex
// not applicable for negative cycle means where weight is considered in negative number 

#include<bits/stdc++.h>
using namespace std;

// #define vi vector<int> 
// #define pii pair<int,int>
// #define vpii vector<pii> 
// #define vvpii vector<vpii> 
// #define rep(i,a,b) for(int i=a;i<b;i++)

// const int INF = 1e5; 

// signed main(){
//     int v, e; cin>>v>>e; 
//     vpii Graph[v+1];
//     rep(i,0,e){
//         int x,y,w; cin>>x>>y>>w; 
//         Graph[x].push_back({y,w});
//         Graph[y].push_back({x,w});
//     }
//     // Distance -> EdgeWeight
//     vi Distance(v+1,INF);
//     int src; cin>>src; 
//     Distance[src] = 0; 
//     set<pii> s; 
//     // set format -> { weight, source/node }
//     s.insert({0,src});
//     while(!s.empty()){
//         auto x = *(s.begin());
//         s.erase(x);
//         for(auto it : Graph[x.second]){
//             if(Distance[it.first] > Distance[x.second] + it.second){
//                 s.erase({Distance[it.first],it.first});
//                 Distance[it.first] = Distance[x.second] + it.second;
//                 s.insert({Distance[it.first],it.first});
//             }
//         } 
//     }
//     for(int i=1;i<=v;i++){
//         if(Distance[i]<INF)
//             cout<<Distance[i]<<" ";
//         else 
//             cout<<-1<<" "; // unreachable nodes
//     }
//     return 0;
// }

#define vi vector<int>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a; i<b; i++)

const int INF = 1e9; 
const int N = 1e5+2;
vi Distance(N, INF); 
vi Parent(N, -1); 
vvi adjL[N];                                    
int v, e; 
int src, dest; 

void getPath(int cur) { 
    if(cur == -1)
        return; 

    getPath(Parent[cur]); 
    cout<<cur<<"->"; 
}

signed main() {
    cin>>v>>e; 

    rep(i,0,e) {
        int u, v, w; cin>>u>>v>>w; 
        adjL[u].push_back({v,w}); 
        adjL[v].push_back({u,w});
    }

    cin>>src>>dest; 
    Distance[src] = 0; 
    set<vi> s;
    s.insert({0,src}); 

    while(!s.empty()) { 
        auto x = *(s.begin());
        s.erase(x); 

        for(auto it : adjL[x[1]]) { 
            if(Distance[x[1]] + it[1] < Distance[it[0]]) {
                s.erase({Distance[it[0]], it[0]});
                Distance[it[0]] = Distance[x[1]] + it[1]; 
                s.insert({Distance[it[0]], it[0]});
                Parent[it[0]] = x[1]; 
            }
        }

    }

    for(int i=0; i<v; i++)
        cout<<Parent[i]<<" "; 
    cout<<endl;

    getPath(6); 
    cout<<"NULL"<<endl;

    for(int i=0; i<v; i++) { 
        cout<<i<<" : "; 
        if(Distance[i]==INF) cout<<-1<<endl;
        else cout<<Distance[i]<<endl;
    }

    return 0; 
}
