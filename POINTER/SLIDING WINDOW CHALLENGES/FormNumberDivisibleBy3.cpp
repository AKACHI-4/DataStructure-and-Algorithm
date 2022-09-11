#include<bits/stdc++.h>
using namespace std;

void NumberFromSubarray(vector<int> a, int k){
    pair<int, int> ans; 
    int sum = 0; 
    for(int i=0;i<k;i++)
        sum += a[i];
    bool found = false;
    if(!(sum%3)){
        ans = make_pair(0, k-1);
        found = true;
    }
    
    for(int j=k;j<a.size();j++){
        if(found)
            break;
        sum = sum + a[j] - a[j-k]; /* Sliding Window Technique */

        if(!(sum%3)){
            ans = make_pair(j-k+1, j);
            found = true;
        }
    }
    if(!found)
        ans = make_pair(-1,0);
    if(ans.first==-1)
        cout<<"No such subarray exists"<<endl; 
    else{
        for(int i=ans.first;i<=ans.second;i++){
            cout<<a[i]<<" ";
        }
    }
}   

int32_t main(){
    vector<int> a = {84,23,45,12,56,82}; 
    int k = 3;
    NumberFromSubarray(a,k);
    return 0;
}