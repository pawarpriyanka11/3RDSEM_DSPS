/*You are given an integer array 'A' of size 'N', sorted in non- decreasing order. You are also given an integer 'target'. Your task
is to write a function to search for 'target' in the array 'A'. If it
exists, return its index in 0-based indexing using Linear Search in
C++/Python/Java*/

#include<iostream>
using namespace std;

class search{
public:
int found=0;

void linear(int a[],int n,int target)
{
     

    for(int i=0;i<n;i++)
    {
       if(a[i]==target)
       {
        found=1;
        cout<<"\nElement found at position: "<<i<<endl;
       }

    }
    if(!found)
    {
        cout<<"\nElement not found!";
    }

}

};

int main()
{
    search ss;
    int *a,n,target;
    cout<<"\nEnter the value of n: ";
    cin>>n;

    a=new int[n];
    cout<<"\nEnter "<<n<<" elements in array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\nEnter the target you want to serach: ";
    cin>>target;
    
    ss.linear(a,n,target);



    return 0;
}
