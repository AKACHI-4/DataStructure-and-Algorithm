#include<bits/stdc++.h>

using namespace std;

class node
{
    public : 
    int data; 
    node* next; 
    node(int val)
    {
        data = val; 
        next = NULL;
    }
}; 
void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n; 
        return ; 
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; 
    }
    temp->next = n; 
    n->next = NULL; 
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

void evenafterodd(node* &head)
{
    node* odd = head; 
    node* even = head->next; 
    node* evenstart = even; 

    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next = even->next; 
        odd = odd->next; 
        even->next = odd->next; 
        even = even->next; 
    }
    if(odd->next != NULL)
    {
        odd->next = evenstart;
        even->next = NULL; 
    }
    else
    {
        odd->next = evenstart;
    }
}

int main()
{
    node* head = NULL; 
    int a[] = {1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        insertAtTail(head, a[i]);
    }
    display(head);

    evenafterodd(head);
    display(head);

    return 0;
}