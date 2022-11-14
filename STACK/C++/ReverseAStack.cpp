#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int> &st, int n)
{
    if(st.empty())
    {
        st.push(n);
        return ; 
    }
    int Top = st.top();
    st.pop();

    InsertAtBottom(st, n);

    st.push(Top);
}
void reverse(stack<int> &st)
{
    if(st.empty())
    {
        return; 
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    InsertAtBottom(st, ele);
}

int main()
{
    stack<int> st; 
    st.push(9);
    st.push(8);
    st.push(7);
    st.push(6);
    st.push(5);

    reverse(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl; 

    return 0;
}