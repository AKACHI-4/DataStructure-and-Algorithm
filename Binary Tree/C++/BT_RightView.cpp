#include<bits/stdc++.h>
using namespace std;

struct Node
{
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

void RightView(Node* root)
{
    if(root == NULL)
    {
        return ; 
    }

    queue<Node*> q; 
    q.push(root);

    /* Level Order Traversal */    
    while(!q.empty())
    {
        int n = q.size(); 
        for(int i=0;i<n;i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i==n-1)
                cout<<curr->data<<" ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
} // TIME COMPLEXITY : O(n)

int32_t main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    RightView(root);

    return 0;
}