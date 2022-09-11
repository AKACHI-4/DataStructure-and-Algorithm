#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define pii pair<int,int> 
#define vii vector<pii> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main(){
    int n, k; 
    cin>>n>>k; 

    vi a(n);

    rep(i,0,n)
        cin>>a[i];

    map<int, int> freq;


    rep(i,0,n){
        int currsize = freq.size(); 
        if(freq[a[i]]==0 && currsize==k)
            break; 
        freq[a[i]]++; 
    }

    vii ans; 
    map<int, int> :: iterator it; 
    for(it=freq.begin();it!=freq.end();it++){
        if(it->ss!=0)
            ans.push_back(make_pair(it->ff,it->ss));
    }

    sort(ans.begin(), ans.end(), greater<pii>());

    vii :: iterator ite; 

    for(ite=ans.begin();ite!=ans.end();ite++){
        cout<<ite->ff<<" -> "<<ite->ss<<endl; 
    }

    return 0; 
}