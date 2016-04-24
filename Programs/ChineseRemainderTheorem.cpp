#include<stdio.h>
#include<iostream>
#include<stdlib.h>


using namespace std;


main()
{
    int r[3],m[3],M,i,n[3],a[10],b[10],c[10],j;
    int temp,k;
    int boo=1;

    for( i = 0 ; i < 3 ; i++ )
    {
        cout<< "Enter "<<i+1<<"  remainder: ";
        cin>>r[i];
        cout<<"Enter "<<i+1<<"  divisor: ";
        cin>>m[i];
        cout<<"\n\n";
    }

    M = m[0]*m[1]*m[2];
    cout<<M;
    cout<<"\n\n";


    for( i = 0 ; i < 3 ; i++ )
    {
        n[i] = M/m[i];
        cout<<n[i]<<"\n";
    }


    for( j = 0 ; j < 10 ; j++ )
    {
        a[j] = m[0]*j + r[0];
         b[j] = m[1]*j + r[1];
         c[j] = m[2]*j + r[2];

    }


    for( j = 0 ; j < 5 ; j++ )
    {
        for( k = 0 ; k < 5 ; k++ )
        {
            if( c[j] == b[k] )
            {

                if( c[j] == a[k+1] )
                {
                    temp = c[j];
                    boo = 0;
                    break;
                }
            }
        }

            if(boo==0)
            {
                break;
            }
        }


     cout<<"\n\n"<<"Least Remainder is: "<<temp<<"\n\n";
     cout<<"Equation will be of type: "<<"x = "<<temp<<" mod "<<"("<<M<<")";

     return 0 ;
}
