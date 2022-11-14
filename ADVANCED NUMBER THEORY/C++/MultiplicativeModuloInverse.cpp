#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+2, MOD = 1e7+4;

// ab + mq = 1
// a and m are co prime number so GCD(a,m) = 1

// y = g

struct eq{
    int b, q, GCD; 
};

eq ExtendedEuclidAlgorithm(int a, int m){
    // base case 
    if(m==0){
        eq ans;
        ans.b = 1;
        ans.q = 0; 
        ans.GCD = a;
        return ans;  
    }

    eq subans = ExtendedEuclidAlgorithm(m,a%m);
    eq ans; 
    ans.GCD = subans.GCD; 
    ans.b = subans.q;
    ans.q = subans.b - (a/m) * subans.q;

    return ans; 
}

int MultiplicativeModularInverse(int a, int m){
    return ExtendedEuclidAlgorithm(a,m).b; 
}
signed main(){
    int a, m; 
    cin>>a>>m; 

    cout<<MultiplicativeModularInverse(a,m)<<endl;

    return 0;
}

// test case discussion
// (17*-1) % 3 -> -2 
// as result is negative so -2%3 -> (-2+3)%3 -> 1 
// method: a%m (a->negative) (a+m)%m -> a%m +  m%m -> a%m + 0 -> a%m (*wrong)