#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if( c=='^' )
        return 3;
    else if( c=='*' || c=='/' ) 
        return 2; 
    else if( c=='+' || c=='-' ) 
        return 1; 
    else
        return -1; 
}

string InfixToPostfix(string s)
{
    stack<char> st; 
    string ans; 

    for(int i=0;i<s.length();i++)
    {
        if( ( s[i]>='a' && s[i]<='z' ) || ( s[i]>='A' && s[i]<='Z' ) || ( s[i]>='0' && s[i]<='9' ) )
                ans += s[i];
        else if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else
        {
            while(!st.empty() && prec(st.top())>prec(s[i]))
            {
                ans += st.top();
                st.pop(); 
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans; 
}

int main()
{
    string ans = InfixToPostfix("(a-b/c)*(a/k-l)");
    cout<<ans<<endl; 
    return 0;
} // "(a-b/c)*(a/k-l)"