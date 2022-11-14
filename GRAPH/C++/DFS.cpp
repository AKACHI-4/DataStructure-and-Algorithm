#include<bits/stdc++.h> 
using namespace std; 

#define vi vector<int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

/* assuming that no. of nodes is 7 */ 
bool check[7+1] = {false}; /* To check that pos. is visited or not */
vi adjL[7+1]; /* undirected adjacent List */

void DFS(int node){
    // inorder
    check[node] = 1;
    cout<<node<<" ";

    // preorder
    vi :: iterator it;
    for(it=adjL[node].begin();it!=adjL[node].end();it++){
        if(!check[*it]){
            DFS(*it);
        }
    }    

    // postorder 
}

signed main(){
    int n, m; 
    cin>>n>>m; 
    /* n->edges, m->nodes */
    int x, y; 
    rep(i,0,m){ 
        cin>>x>>y; 
        /* undirected graph */
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    cout<<"Depth First Search of Given graph : "<<endl;
    DFS(1); /* Assuming that root is 1 */

    return 0; 
}