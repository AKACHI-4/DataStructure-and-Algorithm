#include "bits/stdc++.h"
using namespace std;

/* 
    Approach 1 : Using 2 stacks and Dequeue operation costly 
*/

// class Queue
// {
//     stack<int> s1; 
//     stack<int> s2; 

//     public: 

//     void push(int x) /* EnQueue */
//     {
//         s1.push(x);
//     } // Complexity : O(1)

//     int pop() /* DeQueue */
//     {
//         if(s1.empty() && s2.empty())
//         {
//             cout<<"Queue is empty\n";
//             return -1; 
//         }
//         if(s2.empty())
//         {
//             while(!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop(); 
//             }   
//         }
//         int TopVal = s2.top(); 
//         s2.pop();
//         return TopVal; 
//     } // Complexity : O(n)

//     bool empty()
//     {
//         if(s1.empty() && s2.empty())
//             return true; 
//         return false; 
//     }
// };

/* 
    Approach 2 : Using Function call stack 
*/

class Queue
{
    stack<int> s; 

    public: 

    void push(int x) /* EnQueue */
    {
        s.push(x);
    } // Complexity : O(1)

    int pop() /* DeQueue */
    {
        if(s.empty())
        {
            cout<<"Queue is empty"<<endl; 
            return -1; 
        }
        int x = s.top(); 
        s.pop(); 
        if(s.empty())
            return x; /* return first element of that stack as we know that LIFO property of queue to do that as recursively */
        int item = pop(); /* In-built call stack */
        s.push(x);
        return item; 
    } // Complexity : O(n)

    bool empty()
    {
        if(s.empty())
            return true; 
        return false; 
    }
};

int32_t main()
{
    Queue q; 
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl; 

    q.push(5); 
    cout<<q.pop()<<endl; 
    cout<<q.pop()<<endl; 
    cout<<q.pop()<<endl; 
    cout<<q.pop()<<endl; 
    cout<<q.pop()<<endl; 

    return 0;
}
