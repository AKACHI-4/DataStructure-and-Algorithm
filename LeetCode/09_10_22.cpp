#include<bits/stdc++.h> 
using namespace std;

string robotWithString(string s) {
    string written = "";
    string t = "";
    t.push_back(s[0]); 
    
    cout<<t<<endl;
    int i=1;
    cout<<s[i]-s[i-1]<<endl;
    if(s[i-1]-s[i]==1){
        while(s[i-1]-s[i]==1){
            cout<<s[i]<<endl;
            t.push_back(s[i]);     
            i++;
        }
        written =  t + written;
        reverse(written.begin(),written.end());
        cout<<t<<" "<<written<<endl;
        while(i!=s.size()){
            written.push_back(s[i]);
            i++; 
        }
    }
    else{
        reverse(s.begin(),s.end());
        written = s; 
        cout<<written<<endl;
    }    
    
    return written; 
}

int main(){
    cout<<robotWithString("zza")<<endl;
    return 0; 
}