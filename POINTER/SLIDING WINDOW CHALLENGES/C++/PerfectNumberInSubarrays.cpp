#include<bits/stdc++.h>
using namespace std;

bool Isperfect(int n){
    int sum = 1;
    for(int i=2;i<sqrt(n);i++){
        if(!(n%i)){
            if(i==n/i)
                sum += i;
            else   
                sum += i + n/i;   
        }
    }
    if(sum==n && n!=1)
        return true;
    return false;
} 

int maxSum(int a[], int n, int k){
    if(n<k){
        cout<<"invalid value of k"<<endl; 
        return -1;
    }

    int res = 0;
    for(int i=0;i<k;i++)
        res += a[i];
    int sum = res;
    for(int i=k;i<n;i++){
        sum += a[i] - a[i-k];
        res = max(res, sum);
    }

    return res;
}

int MaxPerfectNumber(int a[], int n, int k){
    
    for(int i=0;i<n;i++){
        if(Isperfect(a[i]))
            a[i] = 1;
        else
            a[i] = 0;
    }

    return maxSum(a,n,k); 
}

int32_t main(){
    int a[] = {28,2,3,6,496,99,8128,24};

    cout<<MaxPerfectNumber(a,8,4);   
    return 0;
}