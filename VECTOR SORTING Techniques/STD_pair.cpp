#include<bits/stdc++.h>

using namespace std;

/* Pair is a STL container which allows us to store pair of values */

bool myCompare(pair <int, int> p1, pair <int, int> p2)
{
    return p1.first < p2.first; 
}

int main()
{
    // pair <int, char> p; 

    // p.first = 3; 
    // p.second = 'H';

    /* 
    we have to reduce an array with follow the order min. to max. we use pair here and make pair of index and elements
    */

   int arr[] = { 10, 16, 7, 14, 5, 3, 2, 9 };

    vector < pair <int, int> > v; 

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        
        // pair < int , int > p;
        // p.first = arr[i];
        // p.second = i; 

        v.push_back(make_pair(arr[i],i));

        /* myCompare is Comparator bcz we have to sort the array in our desirable order */
    }

    sort(v.begin(), v.end(), myCompare );

    for(int i=0;i<v.size();i++)
    {
        arr[v[i].second]=i; 
    }


    for(int i=0;i<v.size();i++)
    {
        cout<<arr[i]<<" "; 
    }

    return 0;
}