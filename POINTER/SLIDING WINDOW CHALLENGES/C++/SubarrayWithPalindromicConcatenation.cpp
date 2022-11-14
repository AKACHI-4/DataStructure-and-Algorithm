#include<bits/stdc++.h>
using namespace std;

bool ispallindrome(int n){
    int temp = n, ans = 0;
    while(temp>0){
        ans = ans*10 + temp%10;
        temp /= 10;
    }
    if(ans==n)
        return true;
    return false;
}

/* To return starting point of pallindromic subarray */
int FindPallindromeSubarray(vector<int> a, int k){
    int num = 0; /* number formed by array elements till k from diff-2 starts */
    for(int i=0;i<k;i++)
        num = num*10 + a[i];
    if(ispallindrome(num))
        return 0;

    for(int j=k;j<a.size();j++){
        num = (num%(int)pow(10,k-1))*10 + a[j];

        if(ispallindrome(num))
            return j-k+1; 
    }
    return -1;
}

int32_t main(){
    vector<int> a = {2,3,5,1,1,5};
    int ans = FindPallindromeSubarray(a,4); 
    if(ans==-1)
        cout<<"pallindromic subarray does not exist"<<endl;
    else{
        for(int i=ans;i<ans+4;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl; 
    }
    return 0;
}