// #include "bits/stdc++.h"
// using namespace std; 

// #define vi vector<int> 
// #define vvi vector<vector<int>>
// #define rep(i,a,b) for(int i=a;i<b;i++)

// int32_t main(){
//     int n,m; cin>>n>>m;
//     /* n->edges, m->vertexes/nodes */
//     vvi adjL(m);
//     vi inDeg(m,0);
//     int x,y; 
//     rep(i,0,n){
//         cin>>x>>y;
//         /* directed graph */
//         adjL[x].push_back(y);
//         inDeg[y]++; 
//     }

//     queue<int> q; 
//     rep(i,0,m){
//         if(inDeg[i]==0)
//             q.push(i);
//     }
//     cout<<q.front()<<endl;
//     while(!q.empty()){ 
//         int a = q.front(); 
//         q.pop(); 
//         cout<<a<<" ";
//         for(auto it : adjL[a]){
//             inDeg[it]--; 
//             if(!inDeg[it])
//                 q.push(it);
//         }
//     }

//     return 0; 
// }

/*

Assumed Graph for input

4 5
0 1
1 2
2 3
3 4

*/

#include<bits/stdc++.h>
using namespace std; 

#define vi vector<int> 
#define vb vector<bool> 
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a;i<b;i++)

vvi adjL;
vb visited;
stack<int> st;
int v, e; 

void DFS(int src) {
    visited[src] = true; 

    for(auto it : adjL[src]) {
        if(!visited[it])
            DFS(it); 
    }

    st.push(src);
}

void TopoSort() { 

    rep(i,0,v) {
        if(!visited[i])
            DFS(i); 
    }
    
}

signed main() { 
    cin>>v>>e; 

    visited = vb(v+1, false);
    adjL = vvi(v+1); 
    rep(i,0,e) { 
        int u, v; cin>>u>>v; 
        adjL[u].push_back(v); 
    }

    TopoSort(); 

    while(!st.empty()){
        cout<<st.top()<<" "; 
        st.pop(); 
    }
    cout<<endl;

    return 0; 
}