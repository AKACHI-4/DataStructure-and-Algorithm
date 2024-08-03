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

void LeftView(Node* root)
{
    if(root==NULL)
    {
        return ; 
    }
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();

        for(int i=1;i<=n;i++)
        {
            Node* temp = q.front(); 
            q.pop();

            if(i==1)
                cout<<temp->data<<" ";
            if(temp->left)  
                q.push(temp->left);
            if(temp->right)  
                q.push(temp->right);
        }
    }
}

int32_t main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    LeftView(root);

    return 0;
}