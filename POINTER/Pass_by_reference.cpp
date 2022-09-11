#include<iostream>

using namespace std;

void swap(int a, int b) /* In call by value function copies those value in new memory address and then when we change their value so actually value is changed but for that new memory location*/
{ 
    int temp = a; 
    a = b; 
    b = temp; 
}

void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int main()
{
    int a = 2; 
    int b = 4;
    
    swap(a,b); // Pass by value
    cout<<a<<" "<<b<<endl; 

    swap(&a,&b); // pass by reference
    cout<<a<<" "<<b<<endl; 

    return 0;
}