#include<bits/stdc++.h>
#include<string>

using namespace std;


/* Reverse a string using recursion */
// void Reverse(string s)
// {
//     if(s.length()==0)
//     {
//         return; 
//     }
//     string fs = s.substr(1);
//     Reverse(fs);
//     cout<<s[0]; 
// }
// int main()  
// {
//     string s = "LOBIRAH";  
//     Reverse(s);
//     return 0;
// }
// void swap(char* a, char *b){
//     int temp = *a; 
//     *a = *b; 
//     *b = temp;
// }
// string reverse(string str,int st, int en, int stop){
//     if(st>stop)
//         return str;
//     swap(&str[st],&str[en]);
//     return reverse(str,st+1,en-1,stop);
// }
// signed main(){  
//     string s = "Adarsh";
//     cout<<reverse(s,0,s.size()-1,(s.size()-1)/2);
//     return 0; 
// }
// void swap(char* a, char *b){
//     int temp = *a; 
//     *a = *b; 
//     *b = temp;
// }
// void reverse(string &str,int st, int en, int stop){
//     if(st>stop)
//         return;
//     swap(&str[st],&str[en]);
//     reverse(str,st+1,en-1,stop);
// }
// signed main(){  
//     string s = "Adarsh";
//     reverse(s,0,s.size()-1,(s.size()-1)/2);
//     cout<<s<<endl;
//     return 0; 
// }

/* Replace pi with 3.14 in string */
// void ReplacePi(string s)
// {
//     if(s.length()==0)
//     {
//         return ; 
//     }
//     if(s[0]=='p' && s[1]=='i')
//     {
//         cout<<"3.14";
//         ReplacePi(s.substr(2));
//     }
//     else
//     {
//         cout<<s[0];
//         ReplacePi(s.substr(1));
//     }
// }
// int main()
// {
//     ReplacePi("pipppppippppipi");
// }


/* Tower Of Hanoi */
// void TowerOfHanoi(int n, char src, char dest, char helper)
// {
//     if(n==0)
//     {
//         return ; 
//     }
//     TowerOfHanoi(n-1,src,helper,dest);
//     cout<<"Move from "<<src<<" to "<<dest<<endl; 
//     TowerOfHanoi(n-1,helper,dest,src);
// }
// int main()
// {
//     TowerOfHanoi(3,'A','B','C');
// }


/* Remove all duplicates from the string */
// string Rem_Dup(string s)
// {
//     if(s.length()==0)
//     {
//         return "";
//     }

//     char ch = s[0];
//     string ans = Rem_Dup(s.substr(1));

//     if(ch==ans[0])
//     {
//         return ans; 
//     }
//     return (ch + ans); 
// }
// int main()
// {
//     string s = "hhhhhhhaaaaarrrriiiii";
//     cout<<Rem_Dup(s);
// }


/* Move all x to the end of the string */
// string MoveXToEnd(string str)
// {
//     if(str.length()==0)
//     {
//         return "";
//     }
//     char ch = str[0];
//     string ans = MoveXToEnd(str.substr(1));

//     if(ch=='x')
//     {
//         return ans + ch;
//     }
//     return ch + ans;
// }
// int main()
// {
//     string str = "axxhedxlkdclxljxx";
//     cout<<MoveXToEnd(str);
// }


/* Generate all substring of a string */
// void SubString(string s, string ans)
// {
//     if(s.length()==0)
//     {
//         cout<<ans<<endl; 
//         return ; 
//     }
//     char ch = s[0];
//     string Fs = s.substr(1);
//     SubString(Fs,ans);
//     SubString(Fs,ans+ch);
// }
// int main()
// {
//     string s = "ABC";
//     SubString(s,"");
// }


/* Generate substrings with ASCII number */
// void SubString_ASCAII(string s, string ans)
// {
//     if(s.length()==0)
//     {
//         cout<<ans<<endl; 
//         return;
//     }

//     char ch = s[0];
//     int code = ch; 
//     string Fs = s.substr(1);

//     SubString_ASCAII(Fs, ans);
//     SubString_ASCAII(Fs, ans + ch);
//     SubString_ASCAII(Fs, ans + to_string(code));

// }
// int main()
// {
//     string s = "AB";
//     SubString_ASCAII(s,"");
// }


/* Print all possible words from phone digits */

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void keypad(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl; 
        return ; 
    }

    char ch = s[0];
    string code = keypadArr[ch-'0'];
    string Fs = s.substr(1);

    for(int i=0;i<code.length();i++)
    {
        keypad(Fs, ans + code[i]);
    } 

}

int main()
{
    keypad("23","");
}