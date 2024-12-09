/*You are required to develop a C++ program to check whether a
given string is a palindrome. A palindrome is a string that reads
the same forward and backward, ignoring punctuation, CO2
capitalization, and spaces. For example, the string "Poor Dan is in
a droop" is a palindrome. To determine whether the string is a
palindrome, you will use a stack data structure to reverse the
characters in the string and compare them to the original*/


#include<iostream>
// #include<cstring>
#include<cctype>
#define MAX 100
using namespace std;


struct stack{
    int top=-1;
    char stack[MAX];
}ss;



class palindrome{
    public:

    void push(char c)
    {
        if(ss.top==MAX-1)
        {
            cout<<"\nOverflow";
        }
        else
        {
            ss.top++;
            ss.stack[ss.top]=c;
        }
    }

    char pop()
    {
        if(ss.top==-1)
        {
            cout<<"\nUnderflown!";
            // return;
        }
        else{
            return (ss.stack[ss.top--]); 
        }
    }

    void check(char s1[])
    {
        palindrome p;

        char processed[MAX];
        int j=0;

        for(int i=0;i<strlen(s1);i++)
        {
            char c=s1[i];
            
            if(isalpha(c))
            {
                processed[j++]=tolower(c);
                p.push(tolower(c));
            }
        }

        processed[j]='\0';

        for(int i=0;i<j;i++)
        {
            if(processed[i]!=p.pop())
            {
                 cout<<"\nProcessed string: "<<processed;
                  cout<<"\nOriginal string is:"<<s1;
                cout<<"\nIt is NOT palindrome!";

                break;
            }
        }
        cout<<"\nProcessed string: "<<processed;
        cout<<"\nOriginal string is:"<<s1;
        cout<<"\nIt is palindrome!"; 
    }

    
};
int main()
{


    palindrome p;

    char s1[MAX];
    cout<<"\nEnter string to check if it is palindrome or not: ";
    cin.getline(s1,MAX);


    p.check(s1);
    
     return 0;
}



