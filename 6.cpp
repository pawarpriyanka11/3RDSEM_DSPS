/*A double-ended queue(deque) is a linear list in which additions
and deletions may be made at either end. Obtain a data
representation mapping a deque into a one-dimensional array. Write C++ program to simulate deque with functions to add and
delete elements from either end of the deque*/



#include<iostream>
#define MAX 10
using namespace std;

class dequeue{
    public:
     int f=-1,r=-1,q[MAX],n;


      void insert_r()
     {
        cout<<"\nEnter the number to inserted(to rare) : ";
        cin>>n;
        if((f==0&&r==MAX-1)||(f==r+1))
        {
            cout<<"\nOverflown!";

        }
        else{
            if(f==-1)
            {
                f=0;
                r=0;
            }
            else if(r==MAX-1)
            {
                r=0;
            }
            else{
                r++;
            }
            q[r]=n;
        }

     }


     void insert_f()
     {
        
        cout<<"\nEnter the number to inseretd(to front): ";
        cin>>n;
        if((f==0&&r==MAX-1)||(f==r+1))
        {
            cout<<"\nOverflown!";

        }
        else{
           if(f==-1)
           {
            f=0;
            r=0;
           }
           else if(f==0){
            f=MAX-1;
           } 
           else{
            f--;
           }
           q[f]=n;

        }

     }

     
     void del_f()
     {

        if(f==-1)
        {
            cout<<"\nUnderflow!";
        }
        else{
            cout<<"\nDeleted element is: (from front)"<<q[f];
            if(f==r)
            {
                f=-1;
                r=-1;
            }
            else if(f==MAX-1)
            {
                f=0;
            }
            else{
                f++;
            }
        }
     }

     void del_r()
     {
        if(r==-1)
        {
            cout<<"\nUnderflown!";

        }
        else{
            cout<<"\nDeleted element is:(from) "<<q[r--];
            if(f==r)
            {
                f=-1;
                r=-1;

            }
            else if(r==0)
            {
                r=MAX-1;
            }
            else{
                r--;
            }
        }

     }



     void display()
     {
        if(f==-1)
        {
            cout<<"\nQueue is empty!";
        }
        else{
            cout<<"\nQueue elements are: ";
            int i=f;
            while(true)
            {
                cout<<q[i]<<" ";
                if(i==r)
                break;

            i=(i+1)%MAX;

            }
            cout<<endl;
        }
     }
};




int main()
{
    dequeue dd;

    int ch;
    do{

        cout<<"\nEnter Your choice:\n1.Insert at rear\n2.insert at front\n3.delete from front\n4.delete from rear\n5.display\n6.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            dd.insert_r();
            break;

            case 2:
            dd.insert_f();
            break;

            case 3:
            dd.del_f();
            break;

            case 4:
            dd.del_r();
            break;


            case 5:
            dd.display();
            break;

            case 6:
            cout<<"\nExiting from the code!!";
            return 0;
            break;

            default:
            cout<<"\nInvalid choice!";

        }

    }while(ch!=6);
     return 0;
}