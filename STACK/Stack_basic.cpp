#include<bits/stdc++.h>
using namespace std;

#define n 100

class Stack
{
    int *a; 
    int top; 

    public : 
    Stack()
    {
        a = new int[n]; /* an array of size 100 will be formed */
        top = -1; /* current top as obvious */
    }

    void push(int val)
    {
        if(top==n-1)
        {
            cout<<"Stack Overflow";
            return;
        }
        top++; 
        a[top] = val; 
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"No element to pop"<<endl; 
            return ;
        }
        top--; 
    }

    int Top()
    {
        if(top == -1)
        {
            cout<<"No element in stack"<<endl; 
            return -1;
        }
        return a[top];
    }

    bool empty()
    {
        return top==-1; 
    }
};

int main()
{
    Stack st; 
    st.push(9);
    st.push(8);
    st.push(7);
    cout<<st.Top()<<endl; 

    st.pop();
    cout<<st.Top()<<endl; 

    st.pop();
    st.pop();
    cout<<st.empty()<<endl;

    st.pop();
    cout<<st.empty()<<endl;


    return 0;
}