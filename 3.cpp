/*Write C++ program to store roll numbers of student in an array
who attended training program in random order. Write function for
a) Searching whether particular student attended training
program or not using linear search . b) Searching whether particular student attended training
program or not using binary search*/

#include<iostream>
#include<iomanip>
using namespace std;
class student{
    public:
    int roll;
    string name,clas;
    int q1,q2,q3,q4,q5;

    void accept()
    {
        cout<<"Enter roll: ";
        cin>>roll;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter clas: ";
        cin>>clas;

    }

   void display()
   {
    cout<<left<<setw(10)<<roll<<setw(10)<<name<<setw(10)<<clas<<endl;

   }


    void survey()
    {
        cout<<"Answer the following(yes=1 and no=0): "<<endl;
        cout<<"Did you enjoy the Trainning program: ";
        cin>>q1;
        cout<<"Did trainning program help you to gain knowledge: ";
        cin>>q2;
        cout<<"Is trainning program help you to gain the skills: ";
        cin>>q3;
        cout<<"Was it inspiring: ";
        cin>>q4;
        cout<<"Should such trainning program more to be conducted:";
        cin>>q5;

        int total=q1+q2+q3+q4+q5;
        float per=(total/5.0)*100;

        cout<<"\nPercent:"<<fixed<<setprecision(2)<<per<<"%"<<endl;
        if(per>80)
        {
            cout<<"\nContinue to conduct such prgram!!!"<<endl;
        }
        else{
            cout<<"\nNot to be counducted! "<<endl;
        }

    
    }


    void search_l(student s1[],int n,int r,string nam)
    {
        int found=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i].roll==r&&s1[i].name==nam)
            {
                found=1;
                cout<<"\n"<<s1[i].name<<" is attending the trainning program!";
                break;
            }
        }
        if(!found)
        {
            cout<<"\n"<<name<<" Is not attending the trainning program!";
        }
        
    }

    void search_b(student s1[],int n,int r,string nam)
    {
        int l=0,h=n-1;
        

        while(l<=h)
        {
            int m=(l+h)/2;
            if(s1[m].roll==r&&s1[m].name==nam)
            {
                cout<<"\n"<<s1[m].name<<" is attending the trainning program!";
                return;
            }
            else if(s1[m].roll<r)
            {
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
            cout<<"\n"<<name<<" is not attending the trainning program!";


    }

    
};

int main()
{
    int ch,n,r;
    string nam;
    student s1[10],s2;

    cout<<"\nEnter the value of n: ";
    cin>>n;

    do{

        cout<<"\n1.Accept\n2.display\n3.Linear serch\n4.Binary search\n5.Survey\n6.exit\n";
        cin>>ch;

        switch(ch)
        {

        case 1:
        for(int i=0;i<n;i++)
        {
            cout<<"\nAccepting details for student: "<<i+1<<endl;

            s1[i].accept();
        }
        break;

        case 2:
        cout<<left<<setw(10)<<"Roll No"<<setw(10)<<"Name"<<setw(10)<<"Class"<<endl;
        for(int i=0;i<n;i++)
        {
            s1[i].display();
        }
        break;

        case 3:
        cout<<"\nEnter the roll number to serch_l: ";
        cin>>r;
        cout<<"Enter the name to serach_l: ";
        cin>>nam;
        s2.search_l(s1,n,r,nam);
        break;

        case 4:
        cout<<"\nEnter the roll number to serch_b: ";
        cin>>r;
        cout<<"Enter the name to serach_b: ";
        cin>>nam;
        s2.search_b(s1,n,r,nam);
        break;

        case 5:
      for(int i=0;i<n;i++)
        {
            cout<<"\nTaking survey for student: "<<i+1<<endl;

            s1[i].survey();
        }
        break;


        case 6:
        cout<<"\nExiting from the code!";
        return 0;
        break;

        default:
        cout<<"\nInvalid case!";
        
      }  

    }while(ch!=6);
    return 0;
}
