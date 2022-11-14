#include<bits/stdc++.h>
using namespace std;

// void pattern(int r, int c, int n){
//     if(r==n)
//         return ;
    
//     if(c<=r){
//         cout<<"* "; 
//         pattern(r,c+1,n);
//     }
//     else{
//         cout<<endl;
//         pattern(r+1,0,n);
//     }
// }
// signed main(){
//     int n; 
//     cin>>n; 
//     pattern(0,0,n);
//     return 0;
// }

/*
    Expected Pattern 

    *
    * *
    * * * 
    * * * *

*/
void pattern(int n, int r, int c, int val){
    if(r>n)
        return; 
    if(c<n){
        if(c<(n-r)){
            cout<<"  ";
            pattern(n,r,c+1,val);
        }
        else{
            cout<<val<<" ";
            pattern(n,r,c+1,val-1);
        }
    }
    else if(){
        
        pattern(n,r,c+1,val+1);
    }
    else{
        cout<<endl; 
        pattern(n,r+1,1,val+1);
    }
}

int main(){
    int n; cin>>n;
    pattern(n,1,1,1);
    return 0;
}

/*
    Expected pattern
          1
        2 1 2 
      3 2 1 2 3
    4 3 2 1 2 3 4
*/