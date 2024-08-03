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

/* APPROACH 1 */
bool GetPath(Node* root, int key, vector<int> &p)
{
    if(root==NULL)
        return false; 
    p.push_back(root->data);
    if(root->data == key)   
        return true;
    if(GetPath(root->left, key, p) || GetPath(root->right, key, p)) 
        return true; 
    p.pop_back(); 
    return false; 
}
int LCA_1(Node* root, int n1, int n2)
{
    vector<int> p1, p2;

    if(!GetPath(root, n1, p1) || !GetPath(root, n2, p2))
        return -1;
    int pc; /* path change */
    for(pc=0;pc<p1.size() && p2.size();pc++)
    {
        if(p1[pc] != p2[pc])
            break; 
    }

    return p1[pc-1];
} // Time Complexity : O(n^2)


/* APPROACH 2 */
Node* LCA_2(Node* root, int n1, int n2)
{
    if(root==NULL)
        return NULL; 
    if(root->data==n1 || root->data==n2)
        return root; 
    Node* LeftLCA = LCA_2(root->left, n1, n2);
    Node* RightLCA = LCA_2(root->right, n1, n2);

    if(LeftLCA && RightLCA){
        return root; 
    }   

    if(LeftLCA != NULL)
        return LeftLCA; 
    return RightLCA; 
} // Time Complexity : O(n)


int main()
{
    Node* root = new Node(1);    
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    int a = LCA_1(root, 4, 6);
    cout<<"LCA : "<<a<<endl;

    Node* a1 = LCA_2(root, 7, 6);
    cout<<"LCA : "<<a1->data<<endl;

    return 0;
}