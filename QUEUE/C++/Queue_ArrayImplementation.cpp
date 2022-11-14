#include<bits/stdc++.h>
using namespace std;

#define n 20

class Queue
{
    int* arr; 
    int front, back; 

    public: 
    Queue()
    {            
        arr = new int[n];
        front = -1; 
        back = -1; 
    }

    void push(int x) /* EnQueue */
    {
        if(back==n-1)
        {
            cout<<"Queue Overflow"<<endl; 
            return; 
        }
        back++; 
        arr[back] = x; 

        if(front==-1)
        {
            front++; 
        }
    }

    void pop() /* DeQueue */
    {
        if(front==-1 or front>back)
        {
            cout<<"No elements in Queue"<<endl; 
            return ; 
        }

        front++; 
    }

    int peek()
    {
        if(front==-1 or front>back)
        {
            cout<<"No elements in Queue"<<endl; 
            return -1; 
        }

        return arr[front];
    }

    bool empty()
    {
        if(front==-1 or front>back)
            return true; 
        return false; 
    }
};

int main()
{
    Queue q; 
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl; 
    q.pop();

    cout<<q.peek()<<endl; 
    q.pop();
    
    cout<<q.peek()<<endl; 
    q.pop();
    
    cout<<q.peek()<<endl; 
    q.pop();

    cout<<q.empty()<<endl; 

    return 0;
}