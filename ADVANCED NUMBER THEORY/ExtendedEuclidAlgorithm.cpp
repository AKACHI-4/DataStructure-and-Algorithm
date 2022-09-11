#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+6, MOD=1e7+2; 

// ax + by = GCD(a,b)
// GCD(a,b) = GCD(b,a%b)
// a%b = a - (a/b) * b

typedef struct equation{
    int x, y, GCD; 
} eq;

// base case discussion 
// b->0 -- ax + 0 = GCD(a,0)
// GCD(a,0) = a
// ax = a -> x = 1 so y = 0(btw it can be anything)

eq ExtendedEuclid(int a, int b){
    // according to maths b only can be zero in terms of finding sub answer
    if(b==0){
        eq ans;
        ans.x = 1; 
        ans.y = 0;
        ans.GCD = a;
        return ans;
    }

    eq subans = ExtendedEuclid(b,a%b); 
    eq ans; 
    ans.GCD = subans.GCD; 
    ans.x = subans.y;
    ans.y = subans.x - (a/b) * subans.y; 

    return ans;
}

signed main(){
    int a, b; 
    cin>>a>>b; 

    eq result = ExtendedEuclid(a,b);

    cout<<"x: "<<result.x<<", "<<"y: "<<result.y<<", "<<"GCD(a,b): "<<result.GCD<<endl;

    return 0;
}