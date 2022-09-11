/* 
Linked List - It is a data structure which stores list of values but not contiguslly as array but connectively
*/

#include<bits/stdc++.h>
using namespace std;

class node
{
    public : 
    int data; 
    node* next; // next is a pointer which point towards next node
    node(int val)
    {
        data = val; 
        next = NULL;    
    }

};

/* here, we will take head by reference bcz we have to modify our linked list */
void insertAtTail(node* &head, int val)
{
    node* n = new node(val);

    if(head==NULL)
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

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head; 
    head = n; 
}

bool search(node* head, int key)
{
    node* temp = head; 
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return true; 
        }
        temp = temp->next; 
    }
    return false; 
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next; 
    }
    cout<<"NULL"<<endl; 
}

/* 
CORNER CASE 
-> When we try to delete starting element
*/

void deleteAtHead(node* &head)
{
    node* todelete = head; 
    head=head->next; 

    /*
    It is necessary to deleter unrequired node from linked list to prevent from memory leakage
    */
    delete todelete; 
}

void deletion(node* &head, int val)
{
    if(head==NULL)
    {
        return ; 
    }
    if(head->next == NULL)
    {
        deleteAtHead(head);
        return; 
    }
    node* temp = head; 
    while(temp->next->data != val)
    {
        temp = temp->next; 
    }
    node* todelete = temp->next; 
    temp->next = temp->next->next; 

    delete todelete;
}

    
int main()
{
    node* head = NULL; 

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);

    insertAtHead(head,0);
    display(head);

    // cout<<search(head,3)<<endl;

    deletion(head,3);
    display(head);

    /* CORNER CASE */

    deleteAtHead(head);
    display(head);

    return 0;
}

