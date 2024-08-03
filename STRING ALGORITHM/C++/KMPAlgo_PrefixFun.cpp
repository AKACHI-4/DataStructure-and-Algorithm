#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi Prefix(string s){
    int n = s.size();
    vi prefix(n,0); 
    for(int i=1;i<n;i++){
        int j = prefix[i-1]; 

        while(j>0 and s[i]!=s[j])
            j = prefix[j-1]; // focus on j here
        if(s[i]==s[j])
            j++;
        prefix[i] = j;
    }
    return prefix; 
} // TC : O(n=s)

signed main(){
    string s1 = "abcabdecab"; 
    vi prefix = Prefix(s1); 
    for(int i=0; i<s1.size(); i++)
        cout<<prefix[i]<<" ";
    cout<<endl;
    string s2 = "abcdeabcfjjjjjjabcdeabcf"; 

    int pos = -1; 
    int i(0), j(0);
    while(i<s2.size()){
        if(s2[i]==s1[j]){
            i++; 
            j++; 
        }
        else{
            if(j>0)
                j = prefix[j-1]; 
            else
                i++; 
        }
        if(j==s1.size()){
            pos = i - s1.size();
            break; 
        }
    } // TC : O(s2.size=t)

    // Total TC : O(s+t)
 
    cout<<pos<<endl;

    return 0;
}