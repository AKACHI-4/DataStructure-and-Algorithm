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

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void GetPointers(Node* root, Node** F, Node** M, Node** L, Node** P){
    if(root==NULL)
        return ; 
    GetPointers(root->left, F, M, L, P);

    if(*P && root->data < (*P)->data )
    {
        if(!*F){
            *F = *P; 
            *M = root; 
        }
        else 
            *L = root; 
    }
    *P = root; 
    GetPointers(root->right, F, M, L, P);
}

void RecoverBST(Node* root){
    Node *Ft, *Md, *Lt, *Pv; 
    Ft = Md = Lt = Pv = NULL; 

    GetPointers(root,&Ft,&Md,&Lt,&Pv);

    if(Ft&&Lt)
        swap(&(Ft->data),&(Lt->data));
    else if(Ft&&Md)
        swap(&(Ft->data),&(Md->data));
}

void inorder(Node* root){
    if(root==NULL)
        return; 
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int32_t main(){
    Node* root = new Node(6);
    root->left = new Node(9);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right = new Node(3);
    root->right->right = new Node(13);

    inorder(root);
    cout<<endl; 

    RecoverBST(root);

    inorder(root);

    return 0; 
}