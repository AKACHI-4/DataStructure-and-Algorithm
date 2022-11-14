#include<bits/stdc++.h>
using namespace std;

#define vc vector<char> 
#define vvc vector<vc> 

void Change(vvc &A, int x, int y){
    A[x][y] = '*';
    // To check whether '0' exist in current's top bottom left right
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        // if yes so also check for that one's top bottom left right
        if(cx>=0 and cx<A.size() and cy>=0 and cy<A[0].size() and A[cx][cy]=='O')
            Change(A,cx,cy); 
    }
}

signed main(){
    int n, m; cin>>n>>m; 
    vvc Board(n,vc(m));
    // input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Board[i][j];
        }
    }
    // edge 'O' conversion
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( (i==0 or i==n-1 or j==0 or j==m-1) and Board[i][j]=='O')
                Change(Board,i,j);
        }
    }
    // Main Process
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Board[i][j]=='O')
                Board[i][j] = 'X';
            else if(Board[i][j]=='*')
                Board[i][j] = 'O';
        }
    }
    // Result 
    cout<<"Final Result : "<<endl;
    for(auto it : Board){
        for(auto i : it)
            cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}