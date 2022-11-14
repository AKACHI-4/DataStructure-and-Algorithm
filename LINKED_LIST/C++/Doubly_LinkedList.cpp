#include<bits/stdc++.h>

using namespace std;

class node
{
    public: 
    int data;
    node* prev;
    node* next; 

    node(int val)
    {
        data = val; 
        prev = NULL; 
        next = NULL; 
    }
};

void insertAtHead(node* &head, int val)
{
    
    node* n = new node(val);
    n->next = head; 
    if(head != NULL)
    {
        head->prev = n; 
    }

    head = n;
}

void insertAtTail(node* &head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return ; 
    }
    node* n = new node(val);
    node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next; 
    }

    temp->next = n; 
    n->prev = temp;  
}


void display(node* head)
{
    node* temp = head; 
    cout<<"NULL<-";
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

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);

    insertAtHead(head, 0);
    display(head);

    return 0;
}