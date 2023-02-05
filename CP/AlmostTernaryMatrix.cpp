#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

void AlmostTernaryMat(){ 
    int n,m; 
    cin>>n>>m; 
    
    vector<vector<int>> mat(n); 
    n /= 2; m /= 2;

    int val = 0; 
    rep(i,0,n){
        if(i%2) val = 1; 
        else val = 0;

        rep(j,0,m){
            if(val==0){
                mat[2*i].push_back(1);
                mat[2*i].push_back(0);
                mat[2*i+1].push_back(0); 
                mat[2*i+1].push_back(1); 
                val = 1; 
            } else { 
                mat[2*i].push_back(0);
                mat[2*i].push_back(1);
                mat[2*i+1].push_back(1); 
                mat[2*i+1].push_back(0); 
                val = 0;
            }
        }
    }

    rep(i,0,2*n){
        rep(j,0,2*m)
            cout<<mat[i][j]<<" "; 
        cout<<endl;
    }

}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    int t; 
    cin>>t; 
    while(t--){
        AlmostTernaryMat(); 
    }
    return 0; 
}