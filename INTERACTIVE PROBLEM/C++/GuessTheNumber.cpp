#include<bits/stdc++.h>
using namespace std;

signed main(){
    int st = 1, en = 10000; 
    int ans = -1; 
    while(st<=en){
        int mid = st + (en-st)/2; 
        cout<<mid<<endl;
        cout<<flush; 
        string s; cin>>s; 
        if(s=="<")
            en = mid-1;
        else{
            ans = max(ans,mid);
            st = mid+1;
        }
        // ans = max(ans,mid);
    }
    cout<<"! "<<ans<<endl;
    cout<<flush;

    return 0;
}