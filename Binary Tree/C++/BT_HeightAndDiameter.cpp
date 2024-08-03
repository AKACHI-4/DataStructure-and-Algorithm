#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public: 
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

/* HEIGHT */
int Height(Node* root)
{
    if(root==NULL)
        return 0; 
    int LHeight = Height(root->left);
    int RHeight = Height(root->right);
    return max(LHeight, RHeight) + 1; 
}

/* DIAMETER */

/* Normal Approach */
int Diameter1(Node* root)
{
    if(root==NULL)  
        return 0;
    int LHeight = Height(root->left);
    int RHeight = Height(root->right);
    int currDiameter = LHeight + RHeight + 1; 

    int LDiameter = Diameter(root->left);
    int RDiameter = Diameter(root->right);

    return max(currDiameter, max(LDiameter, RDiameter));
}

/* Optimised Approach - 1 */
int Diameter2(Node* root, int* height)
{
    if(root==NULL)        
    {
        *height = 0; 
        return 0; 
    }
    int LHeight = 0, RHeight = 0; 
    int LDiameter = Diameter2(root->left, &LHeight);
    int RDiameter = Diameter2(root->right, &RHeight);

    int CurrDiameter = LHeight + RHeight + 1; 
    *height = max(LHeight, RHeight) + 1; 

    return max(CurrDiameter, max(LDiameter, RDiameter));
}

/* Optimised Approach - 2 */
int Diameter3(Node* root) { 
    
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

    // cout<<"Height : "<<Height(root)<<endl;

    // cout<<"Diameter : "<<Diameter1(root)<<endl;
    
    // int height = 0; 
    // cout<<"Diameter : "<<Diameter2(root, &height)<<endl;

    cout<<"Diameter : "<<Diameter3(root)<<endl;

    return 0; 
}