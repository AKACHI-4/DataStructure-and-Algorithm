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
    int n; cin>>n; 

    string str; cin>>str; 

    // 4 variables
    int e = 1, a = 0, ab = 0, abc = 0;

    rep(i,0,n){
        if(str[i]=='a')
            a += e;
        else if(str[i]=='b')
            ab += a; 
        else if(str[i]=='c')
            abc += ab;
        else if(str[i]=='?'){
            abc = 3*abc + ab;
            ab = 3*ab + a;
            a = 3*a + e; 
            e *= 3;
        }
    }

    cout<<abc<<endl;

    return 0;
}