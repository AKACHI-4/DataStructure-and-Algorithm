#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st; 
    bool flag = true; 

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            st.push(s[i]);
        else if(s[i]==')')
        {
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
            {
                flag = false; 
                break; 
            }
        }
        else if(s[i]=='}')
        {
            if(!st.empty() && st.top()=='{')
                st.pop();
            else
            {
                flag = false; 
                break; 
            }
        }
        else if(s[i]==']')
        {
            if(!st.empty() && st.top()=='[')
                st.pop();
            else
            {
                flag = false; 
                break; 
            }
        }
    }

    if(!st.empty())
        return false; 
    return flag; 

}

int main()
{
    string s = "[{({[()]})}]";

    if(isValid(s))
        cout<<"Balanced Paranthesis"<<endl; 
    else
        cout<<"Un-Balanced Paranthesis"<<endl; 

    return 0;
} // " [{({[()]})}] "