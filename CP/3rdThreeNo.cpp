#include<bits/stdc++.h>
using namespace std;
void ThirdThreeNo(){
    int n; 
    cin>>n; 
    if(n%2) cout<<"-1"<<endl; 
    else cout<<1<<" "<<1<<" "<<(1^(n/2))<<endl;
}
int main(){ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    int t; // no. of test cases; 
    cin>>t; 
    while(t--){
        ThirdThreeNo();
    }

    return 0; 
}