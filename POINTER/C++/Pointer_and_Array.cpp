#include<iostream>

using namespace std;

int main()
{
    int a[] = {10, 20, 30};
    cout<<*a<<endl;

    int *ptr = a;

    for(int i=0;i<3;i++)
    {
        cout<<*ptr<<endl;
        ptr++;

        cout<<*(a+i)<<endl; // here we have indexing pointer and when we increment in it so it goes on next index not next memory location.
        // a++; // illegal 
    }

    return 0;
}