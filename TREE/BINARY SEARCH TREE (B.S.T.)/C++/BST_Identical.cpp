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

bool _Identical_(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
        return true; 
    else if(root1==NULL || root2==NULL)
        return false; 
    else{
        bool a = root1->data == root2->data ;
        bool b = _Identical_(root1->left,root2->left);
        bool c = _Identical_(root1->right,root2->right);

        if(a,b,c)
            return true;
        return false;
    }
}

int32_t main()
{
    Node* root1 = new Node(1);
    root1->right = new Node(3);
    root1->right->left = new Node(2);
    root1->right->right = new Node(5);

    Node* root2 = new Node(1);
    root2->right = new Node(3);
    root2->right->left = new Node(2);
    root2->right->right = new Node(5);

    if(_Identical_(root1,root2))
        cout<<"BSTs are Identical"<<endl;
    else
        cout<<"Not Identical"<<endl;
    return 0;
}