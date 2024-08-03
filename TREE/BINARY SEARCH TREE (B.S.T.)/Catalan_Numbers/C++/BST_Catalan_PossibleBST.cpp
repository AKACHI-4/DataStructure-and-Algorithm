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

vector<Node*> ConstructBST(int st, int en)
{
    vector<Node*> trees;
    if(st>en)
    {
        trees.push_back(NULL);
        return trees; 
    }
    for(int i=st;i<=en;i++)
    {
        vector<Node*> leftsubtree = ConstructBST(st, i-1);
        vector<Node*> rightsubtree = ConstructBST(i+1, en);

        for(int j=0;j<leftsubtree.size();j++)
        {
            Node* left = leftsubtree[j];
            for(int k=0;k<rightsubtree.size();k++)
            {
                Node* right = rightsubtree[k];
                Node* root = new Node(i);
                root->left = left; 
                root->right = right; 
                trees.push_back(root);
            }
        }
    }
    return trees; 
}

void preorder(Node* root)
{
    if(root==NULL)
        return ; 
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int32_t main()
{
    vector<Node*> TotalTrees = ConstructBST(1,3);
    for(int i=0;i<TotalTrees.size();i++)
    {
        cout<<(i+1)<<" : ";
        preorder(TotalTrees[i]);
        cout<<endl; 
    }
    return 0;
}