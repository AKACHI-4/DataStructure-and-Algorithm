#include<bits/stdc++.h>
using namespace std;

class node
{
    public: 
    int data; 
    node* next;

    node(int val)
    {
        data = val; 
        next = NULL; 
    }
};

class Queue
{
    node* front; 
    node* back; 

    public: 
    Queue()
    {
        front = NULL; 
        back = NULL; 
    }

    void push(int x) /* EnQueue */
    {
        node* n = new node(x);

        if(front==NULL)
        {
            back = n; 
            front = n;
            return ;
        }
        back->next = n; 
        back = n; 
    }

    void pop() /* DeQueue */
    {
        if(front==NULL)
        {
            cout<<"Queue Underflow"<<endl;
            return ; 
        }
        node* todelete = front; 
        front = front->next; 

        delete todelete;
    }

    int peek()
    {
        if(front==NULL)
        {
            cout<<"No element in queue"<<endl;
            return -1; 
        }  

        return front->data; 
    }

    bool empty()
    {
        if(front==NULL)
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

// v,oir[wfuajd u gflwep