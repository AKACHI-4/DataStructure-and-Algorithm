#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public : 
    int data; 
    Node* left; 
    Node* right; 

    Node(int val)
    {
        data = val; 
        left = NULL; 
        right = NULL; 
    }
};

int search(int PostOrder[], int st, int en, int curr)
{
    for(int i=st;i<=en;i++)
    {
        if(PostOrder[i]==curr)
            return i; 
    }
    return -1; 
}

Node* BuildTree(int PreOrder[], int PostOrder[], int st, int en)
{
    static int idx = 0;

    if( st > en )
        return NULL; 

    Node* node = new Node(PreOrder[idx]);
    idx++; 


    if(st==en)
        return node; 

    int pos = search(PostOrder, st, en, PreOrder[idx]);

    if (pos <= en) {
        node->left = BuildTree(PreOrder, PostOrder, st, pos);
        node->right = BuildTree(PreOrder, PostOrder, pos + 1, en - 1);
    }

    return node; 
}

void InOrder(Node* root)
{
    if(root==NULL)
        return ; 
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main()
{
    int PreOrder[] = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
    int PostOrder[] = { 8, 9, 4, 5, 2, 6, 7, 3, 1 };
    
    Node* root = BuildTree(PreOrder, PostOrder, 0, 8);
    InOrder(root);

    return 0;
}