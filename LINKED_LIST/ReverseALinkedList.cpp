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

/* ITERATIVE WAY TO REVERSE A LINKED LIST */
node* reverse_iterative (node* &head)
{
    node* prevptr = NULL; 
    node* currptr = head; 
    node* nextptr = NULL; 

    while(currptr != NULL)
    {
        /* Intialization of next pointer */
        nextptr = currptr->next; 
        /* change the direction of nodes */
        currptr->next = prevptr; 
    
        prevptr = currptr; 
        currptr = nextptr; 

    }

    return prevptr; 
}

/* RECURSIVE WAY TO REVERSE A LINKED LIST */

node* reverse_recursive (node* &head)
{
    /* head==NULL for those cases where there are an empty linked list */
    if(head == NULL || head->next == NULL)
    {
        return head; 
    }

    node* newhead = reverse_recursive(head->next);
    head->next->next = head; 
    head->next = NULL; 

    return newhead;
}

node* ReverseKNodes (node* &head, int k)
{
    node* prevptr = NULL; 
    node* currptr = head;
    node* nextptr;

    int count = 1; // count till k
    while (currptr != NULL && count <= k )
    {
        nextptr = currptr->next; 
        currptr->next = prevptr; 
    
        prevptr = currptr; 
        currptr = nextptr;

        count++; 
    }

    if(nextptr != NULL)
    {
    head->next = ReverseKNodes(nextptr,k);
    }

    return prevptr; 
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

int main()
{
    node* head = NULL; 

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    display(head);

    // node* newhead1 = reverse_iterative (head);
    // display(newhead1);
    
    // node* newhead2 = reverse_recursive (newhead1);
    // display(newhead2);

    node* reverse = ReverseKNodes(head,3);
    display(reverse);

    return 0;
}