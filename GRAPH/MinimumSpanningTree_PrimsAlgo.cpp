#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vb vector<bool> 
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

const int N = 1e5+2; 
int TreeCost = 0; 
vvi adjL_W[N]; 
vi Distance(N), Parent(N); // vector Distance is made for self check-in and also for bound into the constraints
vb visited(N,false);
const int INF = 1e9;
// Distance -> EdgeWeight

void primsMST(int src){
    // intially let suppose all nodes are far more away from each other meanwhile weight of edges is high
    for(int i=0;i<N;i++)
        Distance[i] = INF;
    // set which will we use to store { wt, node/source }
    set<vi> s; 
    Distance[src] = 0; // bcz we are starting from source so for source to source distance/weight will be zero  
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin()); // format of elements of set is { weight/distance,vertex } <-> { wt, vertex }
        visited[x[1]] = true; // current source/node has been visited
        s.erase(x); // erase x so we can put new nodes greedly 
        int currsrc = x[1]; 
        int currsrcparent = Parent[x[1]];
        int currweight = x[0];
        cout<<"wt: "<<currweight<<" src: "<<currsrc<<" parent: "<<currsrcparent<<endl;
        TreeCost += currweight; 

        // visit neighbour of x[1]/source
        for(auto i : adjL_W[x[1]]){
            // i[0] -> neighbour of new source 
            // if neighbour is already visited so 
            if(visited[i[0]])  continue; 
            
            // greedy approach 
            // Distance -> EdgeWeight
            // if weight/distance of neighbour is high then actual weight 
            if(Distance[i[0]]>i[1]){
                s.erase({Distance[i[0]],i[0]}); // bcz we only need to low weight/Distance Node?
                Distance[i[0]] = i[1]; // coz in format of adjL_W i[1] is weight That's why 
                s.insert({Distance[i[0]],i[0]});
                Parent[i[0]] = x[1]; // bcz we access that through x[1]
            }
        }
    }
}
signed main(){
    int v, e; cin>>v>>e; 
    rep(i,0,e){
        int w,u,v; cin>>w>>u>>v; 
        adjL_W[u].push_back({v,w});
        adjL_W[v].push_back({u,w});
    }
    primsMST(0);
    cout<<"Minimum Spanning Tree Cost : "<<TreeCost<<endl; 
    return 0;
}