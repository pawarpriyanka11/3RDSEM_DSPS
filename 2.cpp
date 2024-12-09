/*The college library has a collection of N books. 
Each book has an associated cost, which is stored in an array in ascending order. Perform the following tasks:

1. Write a function to sort the array of book costs in descending
order. 

2. Write a function to copy the costs of all books with a cost less
than 500 into a new array. 

3. Delete Duplicate Entries: 
Implement two functions:
a) Delete duplicate entries using a temporary array.
 b) Delete duplicate entries without using a temporary array. 
 
 4.Write a function to count the number of books with a cost greater
than 500.*/


#include<iostream>
#include<iomanip>
using namespace std;

class lib
{

    public:
    int cost;
    string name;

    void info()
    {
        cin.ignore();
        cout<<"\nEnetr book name: ";
        getline(cin,name);
        cout<<"\nEnter cost: ";
        cin>>cost;
    }

     void display(lib books[],int n)
    {
        cout<<left<<setw(10)<<"Name"<<setw(10)<<"cost"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<left<<setw(10)<<books[i].name<<setw(10)<<books[i].cost<<endl;
        }
    }

     void sort(lib books[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(books[i].cost<books[j].cost)
                {
                    lib temp=books[i];
                    books[i]=books[j];
                    books[j]=temp;
                }
            }
        }
    }


     void d_l_500(lib books[],int n)
    {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(books[i].cost<500)
            {
                cout << left << setw(10) << books[i].name << setw(10) << books[i].cost << endl;
                c++;
            }
        }
        cout<<"\nNumber of books having cost<500: "<<c<<endl;

    }


     void d_g_500(lib books[],int n)
    {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(books[i].cost>500)
            {
                cout << left << setw(10) << books[i].name << setw(10) << books[i].cost << endl;
                c++;
            }
        }
        cout<<"\nNumber of books having cost>500: "<<c<<endl;
    }


     void delete_dup(lib books[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (books[i].name == books[j].name) {
                // Shift elements to the left to overwrite the duplicate
                for (int k = j; k < n - 1; k++) {
                    books[k] = books[k + 1];
                }
                n--; // Reduce the array size
            } else {
                j++; // Move to the next element if no duplicate
            }
        }
    }
     }


     void delete_dupt(lib books[], int &n) 
    {
    lib temp[n];
    int tempIndex = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < tempIndex; j++) {
            if (books[i].name == temp[j].name) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) temp[tempIndex++] = books[i];
    }

    n = tempIndex;
    for (int i = 0; i < n; i++) books[i] = temp[i];

    cout << "\nRemoved duplicates. The unique array is: "<<endl;
    display(books, n);
      }
    


};

int main()
{
 lib books[50],x;
 int ch,n;

 cout<<"\nEnter the number of records: ";
 cin>>n;

 do{
    cout<<"\nEnter your choice:\n1.insert\n2.display\n3.sort\n4.display<500\n5.display>500\n6.delete_duplicated(without temp array)\n7.delete_duplicated(with temp array)\n8.Exit\n";
    cin>>ch;

    switch(ch)
    {
        case 1:
        for(int i=0;i<n;i++)
        {
            books[i].info();
        }
        break;

        case 2:
        x.display(books,n);
        break;

        case 3:
        x.sort(books,n);
        cout<<"soretd books by its cost:"<<endl;
        x.display(books,n);
        break;

        case 4:
        // cout<<"\nBooks  having cost less than 500: "<<endl;
        x.d_l_500(books,n);
        break;

        case 5:
        // cout<<"\nBooks  having cost greater than 500: "<<endl;
        x.d_g_500(books,n);
        break;

        case 6:
        x.delete_dup(books,n);
        break;

        case 7:
        x.delete_dupt(books,n);
        break;

        case 8:
        cout<<"\nExiting fromt the code!";
        return 0;
        break;

        default:
        cout<<"\nInvalid case!";
        
    }

 }while(ch!=8);

    return 0;
}