// #include <bits/stdc++.h>

// using namespace std;

// int main ()
// {
//     int n, m; 
//     string s; 

//     cin>>n ; 
//     for(int i=0;i<n;i++)
//     {
//         cin>>s; 
//     }
//     cin>>m; 
//     for(int i=0;i<m;i++)
//     {
//         cin>>s;
//     }
//     cout<<s<<endl;

    
//     return 0; 
// }


// int main()
// {
//     int n; 
//     cin>>n; 
    
//     string strings[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>strings[i];
//     }
    
//     int m; 
//     cin>>m; 
    
//     string queries[m];
//     for(int i=0;i<m;i++)
//     {
//         cin>>queries[i];
//     }
    
//     int ans[m];
    
//     for(int i=0;i<m;i++)
//     {
//         ans[i] = 0;
//         for(int j=i;j<n;j++)
//         {
//             if(strings[j]==queries[i])
//             {
//                 ans[i]++;
//             }
//         }
//     }
    
    
//     for(int i=0;i<m;i++)
//     {
//         cout<<ans[i]<<endl; 
//     }
    
     
//     return 0; 
// }

// int main()
// {
    
//     int n, m; 
//     string str; // it will used as both string and query array  
//     unordered_multiset<string> s; // it is a multiset which used to st0ore duplicate element in no particular order.
    
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cin>>str; 
//         s.insert(str);
//     }
    
//     cin>>m; 
//     for(int i=0;i<m;i++)
//     {
//         cin>>str; 
//         cout<<s.count(str)<<endl; 
//     }
    
    
//     return 0; 
// }


#include<bits/stdc++.h>
using namespace std; 

vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
    int x, y, LA=0; 
    vector<vector<int>> arr(n);
    vector<int> ans; 
    
    for(int i=0;i<queries.size();i++)
    {
        x = queries[i][1]; 
        y = queries[i][2];
        
        int idx = ((x^LA)%n);
        
        if(queries[i][0]==1)
        {
            arr[idx].push_back(y);
        }
        else 
        {
            LA = arr[idx][y%arr[idx].size()]; 
            ans.push_back(LA);
        }
    }
    return ans;
}

int main()
{
    int n, q; 
    cin>>n>>q; 
    
    vector<vector<int>> queries(q);
    
    for(int i=0;i<q;i++)
    {
        vector<int> vec(3);
        for(auto i : vec)
        {
            cin>>i; 
            vec.push_back(i);
        }
        queries.push_back(vec);
    }
    
    vector<int> ans = dynamicArray(n, queries);
    
    for (auto i : ans)
    {
        cout<<i<<endl;
    }
    
    return 0; 
}
