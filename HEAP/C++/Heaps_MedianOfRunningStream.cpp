#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second 
#define setBits(x) builtin_popcount(x)

priority_queue<int, vi, greater<int>> pqmin; /* min heap */
priority_queue<int, vi> pqmax; /* max heap */

void insert(int x)
{
    if(pqmin.size()==pqmax.size())
    {
        if(pqmax.size() == 0)
        {
            pqmax.push(x);
            return ; 
        }

        if(x<pqmax.top())
            pqmax.push(x);
        else    
            pqmin.push(x);
    }
    else
    {
        {
            // Two Cases Possible
            // Case 1 : size of maxHeap > size of minHeap 
            // Case 2 : size of minHeap > size of maxHeap 

            if(pqmax.size() > pqmin.size()){
                if(x >= pqmax.top())
                    pqmin.push(x);
                else
                {
                    int temp = pqmax.top();
                    pqmax.pop();
                    pqmin.push(temp);
                    pqmax.push(x);
                }
            }
            else
            {
                if(x <= pqmin.top())
                    pqmax.push(x);
                else{
                    int temp = pqmin.top(); 
                    pqmin.pop();
                    pqmax.push(temp);
                    pqmin.push(x);
                }
            }
        }
    }
}

double findMedian()
{
    if(pqmin.size() == pqmax.size())
        return (pqmin.top()+pqmax.top())/2.0;
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    else    
        return pqmin.top(); 
}

signed main()
{
    int n, a=1; 
    rep(i,0,6)
    {
        cin>>n;
        insert(n);
        cout<<"Median after "<<a++<<" input : "<<findMedian()<<endl; 
    }
    return 0;
}