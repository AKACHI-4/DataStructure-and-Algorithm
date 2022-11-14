#include<bits/stdc++.h>
using namespace std;

signed main(){
    string str1 = "na"; 
    string str2 = "apna collegena"; 

    int n = str1.size(), m = str2.size(); 

    for(int i=0;i<m-n+1;i++){
        if(str2.substr(i,n)==str1)
            cout<<str1<<" found at index "<<i<<endl;
    }
    return 0;
}