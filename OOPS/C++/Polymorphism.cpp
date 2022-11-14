#include<bits/stdc++.h>

using namespace std;

/* Function Overloading */
// class Harekrishna
// {
//     public : 
//         void fun()
//         { 
//             cout<<"I am a function with no arguments"<<endl; 
//         }
//         void fun(int x)
//         { 
//             cout<<"I am a function with int arguments"<<endl; 
//         }
//         void fun(double x)
//         { 
//             cout<<"I am a function with double arguments"<<endl; 
//         }
// };
// int main()
// {
//     Harekrishna obj; 
//     obj.fun(); 
//     obj.fun(4);
//     obj.fun(6.4);
//     return 0;
// }

/* Operator overloading */
// class Complex
// {
//     private : 
//         int real, img; 
//     public : 
//         Complex(int r=0, int i=0)
//         {
//             real = r; 
//             img = i;
//         } // constructor 

//     Complex operator + (Complex const &obj)
//     {
//         Complex res; 
//         res.img = img + obj.img; 
//         res.real = real + obj.real; 
//         return res; 
//     } 

//     void display ()
//     {
//         cout << real <<" + i"<<img<<endl; 
//     }
// };
// int main()
// {
//     Complex c1(12, 7);
//     Complex c2(6, 7);
//     Complex c3 = c1 + c2 ;
//     c3.display(); 
//     return 0; 
// }

/* Virtual function */

class base 
{
    public : 
        virtual void print(){
            cout<<"This is the base class's print function"<<endl; 
        }
        void display(){
            cout<<"This is the base class's display function"<<endl; 
        }
};

class derived : public base
{
    public : 
        void print(){
            cout<<"This is the derived class's print function"<<endl; 
        }
        void display(){
            cout<<"This is the derived class's display function"<<endl; 
        }
};

int32_t main()
{
    base *baseptr; 
    derived d; 

    baseptr = &d; 

    baseptr -> print();
    baseptr -> display();

    return 0; 
}