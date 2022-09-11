#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    multiset<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(5);
    for(auto i : s)
        cout<<i<<" ";
    cout<<endl; 
    /*what if i have to delete only one three*/
    s.erase(s.find(3));
    for(auto i : s)
        cout<<i<<" ";
    cout<<endl; 
    s.erase(3); /* all the three's will be disappear */
    for(auto i : s)
        cout<<i<<" ";
    cout<<endl; 
    return 0;
}