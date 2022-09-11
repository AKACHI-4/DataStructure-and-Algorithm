/* CIRCULAR LINKED LIST */

#include<bits/stdc++.h>

using namespace std;

class node
{
    public : 
    int data; 
    node* next; 

    node(int a)
    {
        data = a; 
        next = NULL;
    }
};
/* Insert a new node in the head of the Linked list */
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);

    if(head == NULL)
    {
        n->next = n; 
        head = n; 
        return ; 
    }

    node* temp = head; 

    while(temp->next != head)
    {
        temp = temp->next; 
    }

    temp->next = n; 
    n->next = head;
    head = n; 
}
/* Insert a new node in the tail of the Linked list */
void insertAtTail(node* &head, int val)
{
    if(head==NULL)
    {
        insertAtHead(head, val);
        return ; 
    }
    node* n = new node(val);
    node* temp = head; 

    while(temp->next != head)
    {
        temp = temp->next; 
    }

    temp->next = n; 
    n->next = head;
}
/* Remove a node from the start of the linked list */
void DeleteAtHead(node* &head)
{
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }

    node* todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}
/* Remove a node from the end of the linked list */
void Deletion(node* &head, int pos)
{
    if(pos==1)
    {
        DeleteAtHead(head);
        return;
    }
    node* temp = head; 
    int count = 1;

    while(count != (pos-1))
    {
        temp = temp->next;
        count++; 
    }

    node* todelete = temp->next;
    temp->next = temp->next->next; 

    delete todelete;    
}
/* Display the linked list */
void display(node* head)
{
    node* temp = head;
    do
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    while(temp != head);
    cout<<"NULL"<<endl; 
}


/* main -> driver function */
int main()
{
    node* head = NULL; 
    insertAtTail(head, 9);
    insertAtTail(head, 8);
    insertAtTail(head, 7);
    insertAtTail(head, 6);
    insertAtTail(head, 5);
    display(head);

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    display(head);

    Deletion(head,3);
    display(head);

    DeleteAtHead(head);
    display(head);

    return 0;
}