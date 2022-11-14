#include<bits/stdc++.h>
using namespace std;

int PostfixEvaluation(string s)
{
    stack<int> st; 

    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            /* 
            first element we took in op2 bcz of the calculation issue
            */
            int op2 = st.top(); 
            st.pop();
            int op1 = st.top(); 
            st.pop();

            switch(s[i])
            {
                case '+' : 
                    st.push(op1+op2);
                    break;
                case '-' :
                    st.push(op1-op2);
                    break;
                case '*' :
                    st.push(op1*op2);
                    break;
                case '/' :
                    st.push(op1/op2);
                    break;
                case '^' :
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}

int main()
{
    int ans = PostfixEvaluation("46+2/5*7+");
    cout<<ans<<endl; 
    return 0;
} // "46+2/5*7+"

// TIME COMPLEXITY : O(l)   where l - length of the string