#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vvi vector<vi> 


vvi Multiply(vvi& a, vvi& b){
    int n = a.size(); 
    vvi ans(n,vi(n,0)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j] += a[i][k] * b[k][j]; 
            }
        }
    }

    return ans;
}

vvi MatrixExponentiate(vvi &a, int n){
    // diagonal element gives us that what is the fibonacci number in curr pos(n)
    if(n==0){
        int size = a.size(); 
        vvi ans(size,vi(size,0)); 
        for(int i=0;i<size;i++)
            ans[i][i] = 1; 
        return ans;
    }
    if(n==1){
        return a; 
    }

    vvi temp = MatrixExponentiate(a,n/2); 
    vvi ans = Multiply(temp,temp); 

    if(n&1) ans = Multiply(ans,a);
    
    return ans;
}

signed main(){
    int n; cin>>n; 

    vvi a = {{1,1},{1,0}}; 
    vvi ans = MatrixExponentiate(a,n);
    
    int size = ans.size(); 
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++) 
            cout<<ans[i][j]<<" "; 
        cout<<endl;
    }

    return 0;
}

// 1 1 2 3 5