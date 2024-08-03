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

Node* LCA(Node* root, int n1, int n2)
{
    if(root==NULL)
        return NULL; 
    if(root->data==n1 || root->data==n2)
        return root; /* Here(means in this level), root will be LCA for the elements */
    Node* left = LCA(root->left, n1, n2); /* finding LCA in left subtree */
    Node* right = LCA(root->right, n1, n2); /* finding LCA in right subtree */
    if(left!=NULL && right!=NULL)
        return root; 
    if(left==NULL && right==NULL)
        return NULL;
    if(left != NULL)    
        return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}

int Distance(Node* root, int k, int D)
{
    if(root==NULL)
        return -1;
    if(root->data == k)
        return D;
    int Left = Distance(root->left, k, D+1);
    if(Left != -1)
        return Left; 
    return Distance(root->right, k, D+1);
}

int DistanceBetweenNodes(Node* root, int n1, int n2)
{
    Node* Lca = LCA(root, n1, n2);

    int d1 = Distance(Lca, n1, 0); /* To find distance between lca and n1 node */
    int d2 = Distance(Lca, n2, 0); /* To find distance between lca and n2 node */

    return d1 + d2; 
}

int32_t main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);

    int ans = DistanceBetweenNodes(root, 4, 5);
    cout<<ans<<endl;

    return 0;
}