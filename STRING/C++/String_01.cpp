 /* Hlo Brother I m the big brother of Character array */

#include<bits/stdc++.h>
#include<string>
#include<iostream>

using namespace std;

// int main()
// {
//     // string str;
//     // cin>>str;
//     // cout<<str; 


//     // string str1(5, 'n');
//     // cout<<str1<<endl;

//     string str;
//     getline(cin, str); // used to store space 
//     cout<<str<<endl;

//     return 0;
// }

/* Different function of string */

int main()
{
    string str; 

    string s1 = "fam",  s2 = "ily";


    /* SIMPLE ADDITION (s1 with s2) */
    cout<<s1+s2<<endl;

    /* APPEND (s1 with s2) */
    s1.append(s2);
    cout<<s1<<endl;

    /* Access a Particular char from a string */  
    cout<<s1[1]<<endl; 

    /* Clear */
    string abc = "rkjlu;jhb hlkjvbkl hilj";
    abc.clear(); 
    cout<<abc<<endl; 

    /* Comparison between two strings */
    string s11="abc", s12="abc";
    if(!s11.compare(s12))
        cout<<"strings are equal"<<endl;
    cout<<s12.compare(s11)<<endl;

    /* To Check that given string is empty and not */
    cout<<s11<<endl; 
    s11.clear(); 
    if(s11.empty())
        cout<<"String is empty"<<endl; 
    else 
        cout<<"String is not empty"<<endl;

    /* Erase Function */
    string ss1 = "nincompoop";
    ss1.erase(3, 3);
    cout<<ss1<<endl;

    /* Find Function */
    cout<<ss1.find("op")<<endl;

    /* Insert Function */
    ss1.insert(3,"com");
    cout<<ss1<<endl;

    /* Size function */
    cout<<ss1.size()<<endl; 
    cout<<ss1.length()<<endl; 

    /* Traverse in string */
    for(int i=0;i<ss1.length();i++)
    {
        cout<<ss1[i]<<endl;
    }

    /* SubString Function */
    string s001 = ss1.substr(6, 4);   
    cout<<s001<<endl; 

    /* Numeric string to integer quicklly */
    string st = "8304"; 
    int x = stoi(st);
    cout<<x+2<<endl;

    /* String TO Integer */
    int y = 786; 
    cout<<to_string(y)+"0"<<endl;

    return 0; 
}