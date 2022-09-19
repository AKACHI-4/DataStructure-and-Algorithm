#include<bits/stdc++.h>

using namespace std;

class student
{
    public: 
    string name; 
    int age; 
    bool isMale; 

    student()
    {
        cout<<"Default constructor"<<endl;   
    } // Default constructor

    student(string s, int n, bool IsMale)
    {
        cout<<"Parameterised constructor"<<endl; 
        name = s; 
        age = n; 
        isMale = IsMale; 
    } // parameterised constructor

    student(student &a)
    {
        cout<<"copy constructor"<<endl; 
        name = a.name; 
        age = a.age; 
        isMale = a.isMale; 
    }

    ~student()
    {
        cout<<"Destructor Called"<<endl; 
    }

    void inside()
    {
        cout<<"Hello I am inside class function"<<endl;
    }

    void outside(); 

    void setName(string s) // to get input for private data members 
    {
        name = s; 
    }

    void getName() // to output private data members 
    { 
        cout<<name<<endl; 
    }

    void printInfo()
    {
        cout<<"Name = ";
        cout<<name<<endl; 
        cout<<"Age = ";
        cout<<age<<endl; 
        cout<<"IsMale = ";
        cout<<isMale<<endl; 
    }
 
    /* Showing Error  */

    // bool operator == (student &a) /* Operator Overloading */
    // {
    //     if(name==a.name && age==a.age && isMale=a.isMale )
    //     {
    //         return true;
    //     }
    //     return false; 
    // }

};

void student :: outside()
{
    cout<<"Hello I am outside class function"<<endl;    
}

int main()
{
    // student a[2]; 
    // for(int i=0;i<2;i++)
    // {
    //     string s;
    //     cout<<"Name = ";
    //     cin>>s;
    //     a[i].setName(s); // to get input for private data members 
    //     // cout<<"Name = ";
    //     // cin>>a[i].name;
    //     cout<<"Age = ";
    //     cin>>a[i].age;
    //     cout<<"IsMale = ";
    //     cin>>a[i].isMale;
    // }

    // for(int i=0;i<2;i++)
    // {
    //     a[i].printInfo();
    // }

    student a("Adarsh", 19, 1); // paremeterised constructor 
    // a.printInfo();

    student b; // default constructor
    
    // student c(a); 
    student c = a; // copy constructor

    b.inside(); // call to function which is declared inside of the class

    b.outside(); // call to function which is declared outside of the class

    /*
        we also have a default copy constructor but for our knowledge here we make a copy constructor 
    */

    if(c==a)
    {
        cout<<"Same"<<endl; 
    }
    else 
    {
        cout<<"Not Same"<<endl;
    }

    return 0;
}