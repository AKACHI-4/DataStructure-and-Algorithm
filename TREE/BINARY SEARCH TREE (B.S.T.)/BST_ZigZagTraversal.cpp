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

void ZigZagTraversal(Node* root)
{
    if(root==NULL)
        return ; 
    stack<Node*> CL, NL; 
    bool LTR = true;

    CL.push(root);

    while(!CL.empty())
    {
        Node* temp = CL.top(); 
        CL.pop(); 
        if(temp)
        {
            cout<<temp->data<<" ";

            if(LTR)
            {
                if(temp->left)
                    NL.push(temp->left);
                if(temp->right)
                    NL.push(temp->right);
            }
            else
            {
                if(temp->right)
                    NL.push(temp->right);
                if(temp->left)
                    NL.push(temp->left);
            }
        }
        if(CL.empty()) /* It means we have been finished one level in our BST */
        {
            LTR = !LTR; 
            swap(CL,NL);    
        }
    }
} // TIME COMPLEXITY : O(n)

int32_t main(void)
{
    Node* root = new Node(12);
    root->left = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    root->right = new Node(15); 

    ZigZagTraversal(root);

    return 0;
}