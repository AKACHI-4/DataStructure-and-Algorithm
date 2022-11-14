/* Implementation of pointer */

#include<iostream>

using namespace std;

void increment(int *a)
{
    (*a)++; 
}

int main()
{
    int a=2; 
    // increment(a); // passing by value 
    // cout<<a<<endl; 

    increment(&a);
    cout<<a<<endl; 

    return 0;
} // Output -> 2 