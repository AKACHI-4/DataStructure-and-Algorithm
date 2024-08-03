#include<bits/stdc++.h>
#include<iostream>

using namespace std;


/* 
Q.1 Write a program to check if a given number is power of 2 or not
*/
// // Note : whenever we perform "and operation" in between "power of 2 and its predecessor" so we will "always get 0" as result 
// bool isPowerOf2(int n)
// {
//     return (n && !(n & n-1));
// }
// int main()
// {
//     cout<<isPowerOf2(14)<<endl;
//     return 0;
// }


/* 
Q.2 Write a program to count the number of ones in binary representation of a number using Brian Kernighan’s Algorithm
*/

// int numberofonce(int n){
//     int count = 0; 
//     while(n){
//         n = n & (n-1); 
//         count++;
//     }
//     return count; 
// }
// int main(){
//     cout<<numberofonce(19);
//     return 0;   
// }


/* 
Q.3 Write a program to generate all possible subsets of a set {a, b, c} 
*/

// Brute force Approach
void subset(int a[], int n){

    for(int i=0;i<(1<<n);i++){
    	vector<int> temp;

        for(int j=0;j<n;j++){
        	cout << i << " " << (1 << j) << endl;

            if (i & (1<<j))
                temp.push_back(a[j]);
        }
        cout<<"---- ";
        for (auto v : temp) cout << v << " ";
        cout << "\n" << endl;
    }

}
int main(){   
    int arr[3] = {2, 3, 5};
    subset(arr, 3);
    return 0; 
}

// recursive approach
// void solve(int idx, int sum, vi arr, int N, vi &ans){
//     if(idx==N){
//         ans.push_back(sum);
//         return ; 
//     }  
//     // include current index element
//     solve(idx+1,sum+arr[idx],arr,N,ans);
//     // exclude current index element
//     solve(idx+1,sum,arr,N,ans);
// }
// vi subsetSums(vi arr, int N){
//     // vector to store sum of all subsets 
//     vi SubsetSum; int idx=0, sum=0; 
//     solve(idx,sum,arr,N,SubsetSum);
//     sort(SubsetSum.begin(),SubsetSum.end());
//     return SubsetSum; 
// }
// Time complexity : O(2^N + 2^NLog(2^N))