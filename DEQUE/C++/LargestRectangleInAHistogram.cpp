#include "bits/stdc++.h"
using namespace std;
int get_max_area(vector<int> a)
{
    int n = a.size(), ans = 0, i = 0; 
    stack<int> st; 
    a.push_back(0); /* if we not need to do handle some last remaining value in stack seprately -> last Bar will be zero */
    while(i<n){
        while(!st.empty() and a[st.top()]>a[i])
        {
            int h = a[st.top()];
            st.pop();
            if(st.empty())
                ans = max(ans, h*i);
            else
            {
                cout<<i<<" "<<st.top()<<endl;;
                int len = i - st.top() - 1; 
                cout<<len<<endl;
                ans = max(ans, h*len);
            }
        }
        cout<<endl;
        st.push(i);
        i++; 
    }
    return ans; 
}
int main()
{
    vector<int> a = {2,1,5,6,2,3};
    cout<<get_max_area(a);
    return 0;
}