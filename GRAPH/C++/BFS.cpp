#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
    
    int n, m; 
    cin>>n>>m; 
    /* n->edges, m->nodes */
    bool check[m+1] = {false}; /* to check that particular position is visited or not */
    vi adjL[m+1]; /* Adjacent List */

    int x, y; 
    rep(i,0,m){
        cin>>x>>y; 
        /* Assuming Undirected graph */
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    check[1] = true;

    cout<<"Breadth First search(BFS) of Given graph : "<<endl;
    while(!q.empty()){
        int a = q.front(); 
        q.pop(); 
        cout<<a<<" ";
        vi :: iterator it;
        for(it=adjL[a].begin();it!=adjL[a].end();it++){
            if(!check[*it]){
                check[*it] = true;
                q.push(*it);
            }
        }
    }
    cout<<endl;

    return 0;
}