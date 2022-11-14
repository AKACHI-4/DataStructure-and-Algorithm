#include<bits/stdc++.h>
using namespace std;
#define n 3
#define m 3

bool dch(char (*a)[n], char x){
    for(int i=0;i<n;i++){
        if(a[i][i]!=x)
            return false;
    }
    return true;
}
bool vch(int j, char (*a)[3], char x){ 
    for(int i=0;i<m;i++){
        if(a[i][j]!=x)
            return false;
    }
    return true;
}
bool hch(int i, char (*a)[n], char x){
    for(int j=0;j<n;j++){
        if(a[i][j]!='0')
            return false;
    }
    return true;
}
bool check(int i, int j, char (*a)[3], char x){
    if(i==j){
        if(dch(a,x) or vch(j,a,x) or hch(i,a,x))
            return true;
    }
    else{
        if(vch(j,a,x) or hch(i,a,x))
            return true;
    }
    return false;
}
void print(char a[n][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }    
}
void f1(char (&a)[n][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            a[i][j]='-';
    }    
}
int main()
{ 
    char a[3][3];
    f1(a);
    bool he=true, v1=false, v2=false; 
    int i=0, j=0, num=0;  
    while(true){
        if(he){
            char T = 'O';
            cout<<"Player 1 turn : "; num++;
            cin>>i>>j; 
            a[i][j] = T; 
            print(a);   
            cout<<'\n';
            if(num>=3){
                if(check(i,j,a,T)){
                    cout<<"Player 1 won !!";
                    return 0; 
                }
            }
        }
        else{
            char T = 'X';
            cout<<"Player 2 turn : "; num++;
            cin>>i>>j; 
            a[i][j] = T; 
            print(a);   
            cout<<'\n';
            if(num>=3){
                if(check(i,j,a,T)){
                    cout<<"Player 2 won !!";
                    return 0; 
                }

            }
        }
        he = !he;
    }
    return 0; 
}