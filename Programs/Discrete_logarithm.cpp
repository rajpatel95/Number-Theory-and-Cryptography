#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std ;

int Power(int x , int y )
{
    int ans;
    ans = x;
    for( int i = 1 ; i < y ; i++ )
    {
        ans = ans*x;
    }
    return ans;
}


main()
{
    int n,x;
    double a[100];
    int i;
    cout<<"Enter any no. : ";
    cin>>n;
    cout<<"\n\n";

    cout<<"Enter no whose modulo u want. : ";
    cin>>x;

    cout<<"\n\n";
    cout<<"Logarithm : "<<"\t"<<"Modulo : "<<"\n";

    for( i=1 ; i <= 7 ; i++ )
    {
        int y;
        y = Power( n , i );
        a[i] = y%x;
        cout<<i<<"      \t        "<<a[i]<<"\n";
    }




}
