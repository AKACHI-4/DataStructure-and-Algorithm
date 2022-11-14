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

struct info
{
    int min; 
    int max; 
    int size; 
    int ans; 
    bool IsBST; 
};

info LargestBSTInBT(Node* root)
{
    if(root==NULL)
        return { INT_MAX, INT_MIN, 0, 0, true };
    if(root->left==NULL && root->right==NULL)
        return { root->data, root->data, 1, 1, true};
    info LeftInfo = LargestBSTInBT(root->left);
    info RightInfo = LargestBSTInBT(root->right);
    
    info curr; 
    curr.size = (1+LeftInfo.size+RightInfo.size);

    if(LeftInfo.IsBST && RightInfo.IsBST && root->data>LeftInfo.max && root->data<RightInfo.min){
        curr.min = min(LeftInfo.min,min(RightInfo.min,root->data));
        curr.max = max(LeftInfo.max,max(RightInfo.max,root->data));

        curr.ans = curr.size; 
        curr.IsBST = true; 

        return curr; 
    }
    curr.ans = max(LeftInfo.ans, RightInfo.ans);
    curr.IsBST = false; 

    return curr; 
}

int32_t main()
{
    Node* root = new Node(15);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(5);

    cout<<LargestBSTInBT(root).ans;

    return 0;
}