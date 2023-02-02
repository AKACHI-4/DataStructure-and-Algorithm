#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

void ArrayRecovery(){
    long n, x; 
    cin>>n>>x; 
    vector<long> ans;
    ans.push_back(x);
    rep(i,1,n){
        cin>>x;
        long c1 = ans.back()-x; 
        long c2 = ans.back()+x;
        if(x==0){
            ans.push_back(c2); 
            continue;
        }
        if(c1>=0 && c2>=0 && c1!=c2){
            cout<<-1<<endl; 
            return;
        }
        ans.push_back(max(c1,c2)); 
    } 
    for(auto it : ans)
        cout<<it<<" "; 
    cout<<endl; 
}
int main(){ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    int t; // no. of test cases; 
    cin>>t; 
    while(t--){
        ArrayRecovery();
    }

    return 0; 
}