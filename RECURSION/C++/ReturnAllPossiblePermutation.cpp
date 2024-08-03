#include<bits/stdc++.h>

using namespace std;


/* Permutation - 1 */

/*
    Problem - Given an array a of distinct integers ("no repeat") retrun all the possible permutations, you can return the answer in any ordrer.
*/

vector<vector<int>> ans;
void permute(vector<int> &a, int idx)
{
    if(idx==a.size())
    {
        ans.push_back(a);
        return ; 
    }
    for(int i=idx;i<a.size();i++)
    {
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]); // sort of backtracking here to stay on last combination. 
    }
    return ; 
}
int32_t main()
{
    int n; 
    // cin>>n; 
    // vector<int> a(n);
    vector<int> a = {1,2,3};
    // for(auto &i : a)
    // {
    //     cin>>i; 
    // }
    permute(a,0);
    for(auto v : ans)
    {
        for(auto i : v)
        {
            cout<<i<<" ";
        }
        cout<<endl; 
    }
    return 0;
}

/* STL Trick */
// int32_t main()
// {
//     int n; 
//     cin>>n; 
//     vector<int> a(n);
//     for(auto &i : a)
//     {
//         cin>>i; 
//     }
//     sort(a.begin(), a.end());
//     do
//     {
//         ans.push_back(a);
//     } while (next_permutation(a.begin(), a.end()));
//     for(auto v : ans)
//     {
//         for(auto i : v)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl; 
//     }
//     return 0;
// }


/* Pemutation - 2 */

/*  
    Problem - Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order. 
*/
// void helper(vector<int> a, vector<vector<int>> &ans, int idx)
// {
//     if(idx == a.size())
//     {
//         ans.push_back(a);
//         return;
//     }
//     for(int i=idx;i<a.size();i++)
//     {
//         /* 
//         below one condition is for avoid duplicates from that vector 
//         we only need those duplicate only once
//         */
//         if(i!=idx && a[i]==a[idx])
//         {
//             continue ;
//         }
//         swap(a[i], a[idx]);
//         helper(a,ans,idx+1);

//     }
// }
// vector<vector<int>> permute(vector<int> nums)
// {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans; 
//     helper(nums, ans, 0);
//     return ans;
// }
// int32_t main()
// {
//     int n;
//     cin>>n; 
//     vector<int> a(n);
//     for(auto &i : a)
//     {
//         cin>>i; 
//     }
//     vector<vector<int>> res = permute(a);
//     for(auto v : res)
//     {
//         for(auto i : v)
//             cout<<i<<" ";
//         cout<<endl; 
//     }
// }

