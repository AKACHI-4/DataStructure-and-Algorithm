#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a = 10; 
    int *aptr; 
    aptr = &a; 

    cout<<aptr<<endl; 

    // /* De-Referencing */
    // cout<<*aptr<<endl;

    // /* here I have to change value of a without change in variable a*/
    // *aptr = 20; 

    // cout<<a<<endl; 
    
    aptr++; // It makes difference of 4 bcz of integer datatype
    cout<<aptr<<endl; 

    return 0;
}