#include<bits/stdc++.h>
using namespace std;

// int peakElement(int a[], int n)
//     {
//         if(n==1)
//             return 0; 
//         int ans = -1; 
//         for(int i=1;i<n;i++)
//         {
//             if(a[i]>a[i-1])
//                 ans = i;
//         }
//         return ans; 
//     }

// int32_t main()
// {
//     int n; cin>>n; 
//     int a[n];
//     for(int i=0;i<n;i++)
//         cin>>a[i];  
//     cout<<peakElement(a, n); 
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n, k; cin>>n>>k; 
//     int mx1 = INT_MIN, mx2 = INT_MIN; 
//     int a[n]; for(int i=0;i<n;i++){cin>>a[i];}
//     int i=n; 
    
    
// }
// int32_t main()
// {
//     int T; cin>>T;
//     while(T--){
//         solve(); 
//     }
//     return 0;
// }

int kthMex(int N, int K, int A[]) {
    int check[N+1] = {0};
    for(int i=0;i<N;i++){
        if(A[i]<=N)
            check[A[i]]++; 
    }
    for(int i=0;i<=N;i++){
        cout<<i<<" "<<check[i]<<endl;
        if(!check[i]){
            if(K==1)
                return i;
            else 
                K--;
        }
    }
    return -1;
}

int main(){
    int a[] = { 5, 13, 1, 19, 5, 0, 3, 12, 17, 9 }; 
    cout<<kthMex(10,3,a)<<endl;
    return 0; 
}