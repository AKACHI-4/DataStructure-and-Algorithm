#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

const int INF = 1e7; 

signed main(){
    int v, e; cin>>v>>e; 
    vvi GRAPH(v,vi(v,INF)); 
    rep(i,0,e){
        int x,y,w; cin>>x>>y>>w;
        GRAPH[x][y] = w;
    }

    // "-" -> infinity just for Program

    cout<<"Adjacency Matrix of given graph : "<<endl;
    rep(i,0,v){
        rep(j,0,v){
            if(i==j)
                cout<<0<<" ";
            else if(GRAPH[i][j]==INF)
                cout<<"-"<<" ";
            else
                cout<<GRAPH[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl; 

    vvi Distance = GRAPH; 
    rep(k,0,v){ // To perform relaxation peforms 'n-times' in GRAPH at every node
        rep(i,0,v){
            rep(j,0,v){
                // i,j -> actual graph traversal 
                Distance[i][j] = min(Distance[i][j], Distance[i][k]+Distance[k][j]);
            }
        }
    }

    cout<<"Graph After Relaxation"<<endl;
    rep(i,0,v){
        rep(j,0,v){
            if(i==j)
                cout<<0<<" ";
            else if(Distance[i][j]==INF)
                cout<<"-"<<" ";
            else
                cout<<Distance[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}