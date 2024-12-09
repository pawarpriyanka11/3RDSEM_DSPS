/*Pizza parlor accepting maximum M orders. Orders are served in
first come first served basis. Order once placed cannot be
cancelled. Write C++ program to simulate the system using queue
using array.*/

#include<iostream>
#include<iomanip>
#define MAX 2
using namespace std;

class pizza
{
    public:
    string type,size;
    int price,count;

};

class queue{
    public:
    pizza pz;
    int f=-1,r=-1;
    pizza q[MAX];

    void order()
    {
        if(r==MAX-1)
    {
        cout<<"OVERFLOW!";
    }
    else{
        cout<<"\nEnter type of pizza: ";
        cin>>pz.type;
        cout<<"\nEnter price of pizza: ";
        cin>>pz.price;
        cout<<"\nEnter count of pizza: ";
        cin>>pz.count;
        cout<<"\nEnter size of pizza: ";
        cin>>pz.size;

        r++;
        q[r]=pz;
        if(f==-1)
        {
            f=0;
            r=0;
        }
         cout<<left<<setw(10)<<"Type"<<setw(10)<<"Price"<<setw(10)<<"Size"<<setw(10)<<"Count"<<endl;
         cout<<left<<setw(10)<<pz.type<<setw(10)<<pz.price<<setw(10)<<pz.size<<setw(10)<<pz.count<<endl;
 
    }

   
    }







    void serve()
    {
        if(f==-1)
        {
            cout<<"\nUNDERFLOW!";

        }
        else{
            cout<<left<<setw(10)<<"Type"<<setw(10)<<"Price"<<setw(10)<<"Size"<<setw(10)<<"Count"<<endl;
    cout<<left<<setw(10)<<pz.type<<setw(10)<<pz.price<<setw(10)<<pz.size<<setw(10)<<pz.count<<endl;
    f++;
    if(f>r)
    {
        f=-1;
        r=-1;
    }

        }
    }
};


int main()
{

    int ch;
    queue q;
    do{
       cout<<"\nEnter your choice:\n1.Order Pizza\n2.Server Order\n3.Exit\n";
       cin>>ch;

       switch(ch)
       {
        case 1:
        q.order();
        break;

        case 2:
        q.serve();
        break;

        case 3:
        cout<<"\nExiting from the code!";
        return 0;
        break;

        default:
        cout<<"\nInvalid case!";
        
       }
    }while(ch!=3);
     return 0;
}

