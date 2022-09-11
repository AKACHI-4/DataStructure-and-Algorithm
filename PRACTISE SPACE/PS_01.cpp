#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans; 
    int n=nums.size()-1;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans; 
}
signed main(){
    vector<int> a = { 3, 2, 4 };
    vector<int> ans = twosum(a, 6);
    for(int i)
    return 0;
}