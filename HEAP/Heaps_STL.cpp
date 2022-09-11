#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define pii pair<int,int> 
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second 
#define setbits(x) builtin_popcount(x) 


signed main(){
    priority_queue<int, vector<int>> a; /* Max Heap */
    a.push(1);
    a.push(2);
    a.push(3);

    cout<<a.top()<<endl; 
    a.pop();
    cout<<a.top()<<endl;

    cout<<endl;
    
    priority_queue<int, vector<int>, greater<int>> b; /* Min Heap */
    b.push(1); 
    b.push(2); 
    b.push(3); 

    cout<<b.top()<<endl;
    b.pop();
    cout<<b.top()<<endl; 
    
    return 0;
}