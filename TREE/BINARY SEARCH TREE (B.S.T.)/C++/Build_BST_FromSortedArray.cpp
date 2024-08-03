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

Node* SortedArrayTo_BST(int arr[], int st, int en)
{
    if(st>en)
        return NULL; 
    int mid = (st+en)/2; 
    Node* root = new Node(arr[mid]);

    root->left = SortedArrayTo_BST(arr, st, mid-1);

    root->right = SortedArrayTo_BST(arr, mid+1, en);

    return root; 
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
    int arr[] = {10, 20, 30, 40, 50};

    Node* ans = SortedArrayTo_BST(arr, 0, 4);

    preorder(ans);

    return 0;
}