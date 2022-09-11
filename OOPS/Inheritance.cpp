#include<bits/stdc++.h>

using namespace std;


/* Single Inheritance */

// class A
// {
//     public : 
//         void func()
//         {
//             cout<<"A class"<<endl; 
//         }
// };
// class B : public A 
// {
// };
// int main()
// {
//     B b; 
//     b.func();    
//     return 0;
// }


/* Multiple Inheritance */

// class A
// {
//     public : 
//         void Afunc()
//         {
//             cout<<"A class"<<endl; 
//         }
// };

// class B 
// {
//     public : 
//         void Bfunc()
//         {
//             cout<<"B Class"<<endl;
//         }
// };

// class C : public A, public B
// {
//     public : 
// };

// int main()
// {
//     C c; 
//     c.Afunc();
//     c.Bfunc();
// }


/* Multi-level Inheritance */

// class A
// {
//     public : 
//         void Afunc()
//         {
//             cout<<"A class"<<endl; 
//         }
// };
// class B : public A
// {
//     public : 
//         void Bfunc()
//         {
//             cout<<"B class"<<endl; 
//         }
// };
// class C : public B
// {
//     public :      
// };
// int main()
// {
//     C c; 
//     c.Bfunc(); 
//     c.Afunc(); 
// }


/* Hybrid Inheritance */

// class A
// {
//     public : 
//         void Afunc()
//         {
//             cout<<"A Class"<<endl; 
//         }
// };
// class B : public A 
// {
//     public : 
//         void Bfunc()
//         {
//             cout<<"B Class"<<endl; 
//         }
// };
// class C
// {
//     public : 
//         void Cfunc()
//         {
//             cout<<"C Class"<<endl; 
//         }
// };
// class D : public C, public B
// {
//     public : 
// };
// int main()
// {
//     D d; 
//     d.Afunc();
//     d.Bfunc();
//     d.Cfunc();
// }


/* Hierarchial Inheritance */

// class D
// {
//     public : 
//     void Dfunc()
//     {
//         cout<<"D Class"<<endl; 
//     }
// };
// class E
// {
//     public : 
//     void Efunc()
//     {
//         cout<<"E Class"<<endl; 
//     }
// };
// class F
// {
//     public : 
//     void Ffunc()
//     {
//         cout<<"F Class"<<endl; 
//     }
// };
// class G
// {
//     public : 
//     void Gfunc()
//     {
//         cout<<"G Class"<<endl; 
//     }
// };
// class B : public D, public E
// {
//     public : 
//     void Bfunc()
//     {
//         cout<<"B Class"<<endl; 
//     }
// };
// class C : public F, public G
// {
//     public : 
//     void Cfunc()
//     {
//         cout<<"C Class"<<endl; 
//     }
// };
// class A : public B, public C
// {
//     public:
// };
// int main()
// {
//     A a; 
//     a.Bfunc();
//     a.Cfunc();
//     a.Dfunc();
//     a.Efunc();
//     a.Ffunc();
//     a.Gfunc();
// }