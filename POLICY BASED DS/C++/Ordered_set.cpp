#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

signed main(){  
    int qu; cin>>qu; 
    oset<int> s; 
    while(qu--){
        int type; cin>>type; 
        if(type==1){
            int x; cin>>x; 
            s.insert(x); 
        }else if(type==2){
            int x; cin>>x; 
            cout<<*s.find_by_order(x)<<endl;
        }else{
            int x; cin>>x; 
            cout<<s.order_of_key(x)<<endl;
        }
    }
    return 0;
}// TC : O(logn)
