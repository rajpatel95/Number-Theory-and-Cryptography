#include<iostream>
#include<math.h>


using namespace std;

int gcd(int a , int b);

main()
{
    int a,b;
    int r;

    cout<<"Enter no 1: ";
    cin>>a;
    cout<<"\n\n"<<"Enter no 2: ";
    cin>>b;


    if(gcd(a,b)==1)

    {
        cout<<"\n\n Numbers are co prime";
    }

    else

    {
        cout<<"\n\n Numbers are not co prime";
    }


}

int gcd(int a , int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd( b , a%b );
    }
}

