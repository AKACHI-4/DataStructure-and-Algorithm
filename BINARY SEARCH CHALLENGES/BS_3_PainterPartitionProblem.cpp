#include<bits/stdc++.h>
using namespace std;

int Feasible(int B[], int n, int Lm){
    int sum=0, Painter=1;
    for(int i=0;i<n;i++){
        sum += B[i];
        if(sum>Lm){
            sum = B[i];
            Painter++; 
        }
    }
    return Painter;
}

int Painters_Partition(int B[], int n, int m){
    int mx = INT_MIN, TL = 0; 
    for(int i=0;i<n;i++){
        mx = max(mx, B[i]);
        TL += B[i];
    }
    int s = mx, e = TL; 
    while(s<e){
        int mid = (s+e)/2;
        int Painters = Feasible(B,n,mid);
        if(Painters<=m)
            e = mid; 
        else
            s = mid+1;
    }
    return s;
}

int32_t main(){
    int B[] = {10,20,30,40};
    int n = 4, m = 2; 
    int ans = Painters_Partition(B,n,m);
    cout<<"Minimum time taken to paint boards : "<<ans; 
    return 0;
}