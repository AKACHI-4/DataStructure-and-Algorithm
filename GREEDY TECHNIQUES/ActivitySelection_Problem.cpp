#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int st,en;
        cin>>st>>en;
        v.push_back({st,en});
    }
    sort(v.begin(),v.end(),[&](vector<int> &a, vector<int> &b){
        return a[1] < b[1] ;
    }); 
    int ans = 1;
    int end = v[0][1];

    for(int i=1;i<n;i++){
        if(v[i][0]>=end){
            ans++; 
            end = v[i][1];
        }
    }

    cout<<ans<<endl; 

    return 0;
}