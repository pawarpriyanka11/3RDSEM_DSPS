/*You are tasked with developing a calculator application that can
evaluate mathematical expressions provided by users. To simplify
the evaluation process, you need to first convert the given infix
expressions (which use standard mathematical notation with
operators placed between operands) into postfix expressions
(where operators are placed after their operands). The program
should implement the conversion process using a stack-based
algorithm and output the equivalent postfix expression for any
valid infix expression provided.*/


#include<iostream>
#include<stack>
#include<string>
using namespace std;

class calci{
    public:

    int pre(char op)
    {
        if(op=='+'||op=='-') return 1;
        if(op=='*'||op=='/') return 2;
        if(op=='^') return 3;
        return 0;
    }
    
    bool isOperator(char op)
    {
        return(op=='+'||op=='-'||op=='*'||op=='/'||op=='('||op==')'||op=='^');
    }

    string intopost(string infix)
    {
        stack<char> s;
        string postfix="";

        for(int i=0;i<infix.length();i++)
        {
            char c=infix[i];

            // if (isspace(c)) continue;
            if(isalnum(c))
            {
                postfix+=c;
            }
            else if(c=='(')
            {
                s.push(c);
            }
            else if(c==')')
            {
                while(!s.empty()&&s.top()!='(')
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.pop();
            }
            else if(isOperator(c))
            {
                while(!s.empty()&&pre(s.top())>=pre(c))
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

            while(!s.empty())
            {
                postfix+=s.top();
                s.pop();
            }
        
        return postfix;
    }





};
int main()
{

    string infix;
    calci ppx;
    
    cout<<"\nEnter the infix expression: ";
    cin>>infix;

    string postfix=ppx.intopost(infix);
    cout<<"\nPostifix expression is: "<<postfix<<endl;

     return 0;
}