/* 

DETECTION OF CYCLE LINKED LIST 

It is based upon floyd and hare-tortise algoritham. 

here we have a hare (fast pointer) which moves forward with 2 nodes while tortise (slow pointer) moves forward with 1 nodes it both the pointer meet each other while traversing then they are traversing in a cyclic linked list. 

*/

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

void InsertAtTail(node* &head, int val)
{
    node* n = new node(val);
    
    if(head == NULL)
    {
        head = n; 
        return ; 
    }

    node* temp = head; 
    while(temp->next != NULL)
    {
        temp = temp->next; 
    }
    temp->next = n;
}

void makeCyclicLL(node* &head, int pos)
{

    node* temp = head; 
    node* startnode; 

    int count = 1; 

    while(temp->next != NULL)
    {
        if(count == pos)
        {
            startnode = temp;
        }
        temp = temp->next; 
        count++;
    }
    /*
    After coming out from this loop there will be temp->next = NULL
    */

    temp->next = startnode; 

}

bool DetectCycleInLL(node* &head)
{
    node* slow = head; 
    node* fast = head; 

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next; 
        fast = fast->next->next; 
    
        if(fast == slow)
        {
            return true;
        }
    }
    return false;
}

/* 

REMOVAL OF CYCLE FROM A LINKED LIST 

keep a pointer (slow or fast) *(hare or tortaise) into the head now move both pointer either which is in head or not in head by 1 move once. after sometime, we get that next of fast and slow is same then point one node (which was not in head at previous ) to the NULL. 

*/

void RemoveCycleInLL (node* &head)
{   
    node* slow = head; 
    node* fast = head; 

    /*
    here we use "do-while loop" bcz intially value of slow and fast pointer is same. 
    */

    do
    {

        slow = slow->next; 
        fast = fast->next->next; 

    } while (slow != fast);
    
    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL; 

}   

void display(node* head)
{
    node* temp = head; 

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next ; 
    }

    cout<<"NULL";
}

int main()
{
    node* head = NULL; 

    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    
    makeCyclicLL(head,3);
    // cout<<DetectCycleInLL(head)<<endl;

    // RemoveCycleInLL(head);
    // cout<<DetectCycleInLL(head)<<endl;



    return 0;
}