#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    /*stores unique element*/
    // set<int> s;
    // s.insert(1);
    // s.insert(3);
    // s.insert(2);
    // s.insert(3);
    // for(auto i : s)
    //     cout<<i<<" ";
    // cout<<endl; 
    // for(auto i = s.begin(); i != s.end(); i++)
    //     cout<<*i<<" ";
    // cout<<endl; 
    // for(auto i = s.rbegin(); i != s.rend(); i++)
    //     cout<<*i<<" ";
    // cout<<endl; 
    // cout<<s.size()<<endl;

    /* custom comparator */
    // set<int, greater<int> > s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(3);
    // for(auto i : s)
    //     cout<<i<<" ";
    // cout<<endl; 

    /* Lower/Upper_Bound() */
    // set<int> a;
    // a.insert(1);
    // a.insert(3);
    // a.insert(5);
    // cout<<*a.lower_bound(2)<<"\n";
    // cout<<*a.lower_bound(3)<<"\n";
    // cout<<*a.upper_bound(3)<<"\n";
    // cout<<(a.upper_bound(5)==a.end())<<"\n";
    // a.upper_bound(5) returns a.end !!
    // The set::lower_bound() is a built-in function in C++ STL which returns an iterator pointing to the element in the container which is equivalent to k passed in the parameter. In case k is not present in the set container, the function returns an iterator pointing to the immediate next element which is just greater than k. If the key passed in the parameter exceeds the maximum value in the container, then the iterator returned points to the element beyond last element in the set container that is set.end(). 

    /* ERASE */
    // set<int> s; 
    // s.insert(1);
    // s.insert(3);
    // s.insert(5);
    // s.insert(2);
    // s.erase(2);
    // s.erase(s.begin());
    // for(auto i : s)
    //     cout<<i<<" ";
    // cout<<endl;
    // cout<<s.size()<<endl;

    /* UNORDERED SET */
    unordered_set<int> s; 
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(7);
    s.insert(2);
    for(auto i : s)
        cout<<i<<" ";
    cout<<"\n";
    s.erase(4);
    s.erase(7);
    s.erase(s.begin());
    for(auto i : s)
        cout<<i<<" ";
    cout<<"\n";    

    return 0;
}

