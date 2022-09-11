#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a = 10; // stored in stack 

    /* we will use -new- operator here it is used to allocate memory dynamically in heap */
    int *p = new int(); 

    *p = 10; // p point memory address of -a- in heap 

    // now we can access a as long as we can now a act like a global variable

    /* In heap and DP, it is nessesary that if we allocate the memory dynamically in heap so after completing our work we also have to de-allocate that memory */
    
    delete(p); // deallocate memory in heap

    /* 
        There are no data in heap now means value of a is not there we have been deallocated it But our pointer -p- still point in heap these type of pointer is known as dangling pointer

        so we should not have dangling pointer so we need to remove it. 
    */  

    p = new int[4]; 
   /* here we allocate memory dynamically in heap for an array of 4 size */
   
   /* now pointer -p- will point 0th index element of our array */

    delete[] p; 
    /* It deallocate full block of memory or delete our array from/in heap which is pointed by pointer -p- */
    
    p = NULL; 
    /* now p points to NULL it means heap is totally de allocated from our memory now */

    return 0;
}