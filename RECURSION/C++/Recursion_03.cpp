#include<bits/stdc++.h>

using namespace std;

/* Print all possible permutations of a string */
// void Permutation(string s, string ans)
// {
//     if(s.length()==0)
//     {
//         cout<<ans<<endl; 
//         return; 
//     }
//     for(int i=0;i<s.length();i++)
//     {
//         char ch = s[i];
//         string ROS = s.substr(0,i)+s.substr(i+1); // 0->starting point and i->length it means start from 0th index till i length
//         Permutation(ROS,ans+ch);
//     }
// }
// int main()
// {
//     Permutation("ABC", "");
//     return 0;
// }


/* Count the number of paths possible from start point to end point in gameboard */
// int CountPath(int s, int e)
// {
//     if(s==e)
//     {
//         return 1; 
//     }
//     if(s>e)
//     {
//         return 0; 
//     }
//     int Count = 0; 
//     for(int i=1;i<7;i++)
//     {
//         Count += CountPath(s+i,e);
//     }
//     return Count; 
// }
// int main()
// {
//     cout<<CountPath(1,4);
// }


/* Count the number of paths possible in a maze */
int CountPathMaze(int n, int i, int j)
{
    if(i==n-1 && j==n-1)
    {
        return 1; 
    }
    if(i>=n || j>=n)
    {
        return 0; 
    }

    return CountPathMaze(n,i+1,j) + CountPathMaze(n,i,j+1);

}
int main()
{
    cout<<CountPathMaze(3,0,0);
}
