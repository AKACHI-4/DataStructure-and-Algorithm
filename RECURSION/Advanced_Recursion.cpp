#include<bits/stdc++.h>

using namespace std;

/* Tiling Problems */

// int TilingWays(int n)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     if(n==1)
//     {
//         return 1; 
//     }
//     return TilingWays(n-1) + TilingWays(n-2); // Vertical + Horizontal 
// }
// int main()
// {
//     cout<<TilingWays(4)<<endl; 
//     return 0;
// }


/* Friends Pairing Problem */
// int FriendsPairing(int n)
// {
//     if( n==0 || n==1 || n==2 )
//     {
//         return n; 
//     }

//     return FriendsPairing(n-1) + FriendsPairing(n-2)*(n-1);
// }
// /* FriendsPairing(n-2)*(n-1) -> when 1st member with their pair one */
// int main()
// {
//     cout<<FriendsPairing(3);
// }


/* 0-1 Knapshack problem */ 

int Knapshack(int val[], int wt[], int n, int W) // W is weight of knapshack and n is no. of items
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(wt[n-1]>W) /* wt[n-1] -> weight of nth item */
    {
        return Knapshack(val, wt, n-1, W); /* here we leave the nth item bcz of high weight */
    }
    return max((Knapshack(val,wt,n-1,W-wt[n-1]) + val[n-1]),Knapshack(val,wt,n-1,W));
    /*

    (Knapshack(val,wt,n-1,W-wt[n-1]) + val[n-1]) -> value if we include/consider nth item as per 1 base indexing bcz it can be have high price ( val[n-1] -> bcz we want prise of all those items which is in knapsack )

    Knapshack(val,wt,n-1,W)); -> value if we didn't include/consider nth item as per 1 base indexing bcz it have low price (* here we leave the nth item bcz of low price )
    
    */
}
int main()
{
    int wt[] = {10,20,30};
    int val[] = {100,50,150};
    int W = 50;
    cout<<Knapshack(val,wt,3,W);
}