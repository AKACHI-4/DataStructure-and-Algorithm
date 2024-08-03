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

/* Case 1 : Node's Subtree */
void SubtreeNodes(Node* root, int k)
{
    if(root==NULL || k<0)
        return ; 
    if(k==0)
    {
        cout<<root->data<<" ";
        return ; 
    }

    SubtreeNodes(root->left, k-1);
    SubtreeNodes(root->right, k-1);
}

/* Case 2 : Node's Ancestors */

/* part 1 : distance from target nodes to ancestors -- after using this our case 2 will be change in case 1 */
int NodesAtK(Node* root, Node* target, int k)
{
    if(root==NULL)
        return -1; 
    if(root==target){
        SubtreeNodes(root, k);
        return 0; 
    }

    int dL = NodesAtK(root->left, target, k);
    if(dL != -1)
    {
        if(dL + 1 == k)
            cout<<root->data<<" ";
        else{
            SubtreeNodes(root->right, k-dL-2);
        }
        return 1+dL; 
    }

    int dR = NodesAtK(root->right, target, k); 
    if(dR != -1){
        if(dR+1 == k)
            cout<<root->data<<" ";
        else{
            SubtreeNodes(root->left, k-dR-2);
        }
        return 1+dR;
    }

    return -1; 
}

int32_t main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);

    NodesAtK(root, root->left, 1);

    return 0;
}