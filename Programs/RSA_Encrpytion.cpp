#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>

using namespace std;

long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
void privatekey();
void publickey();





void publickey()
{
    cout<<"\n\n"<<"The Public keys are:";
    for( i=0;i<j-1;i++)
    {
    cout<<"\n\n"<<"{ "<<e[i]<<" , "<<n<<" }"<<"\n";
    }
}


void privatekey()
{
     cout<<"\n\n"<<"The Private keys are:";
    for( i=0 ; i<j-1 ; i++)
    {
        cout<<"\n\n"<<"{ "<<d[i]<<" , "<<n<<" }"<<"\n";
    }
}



main()
{
        cout<<"\nENTER FIRST PRIME NUMBER : \t";
        cin>>p;
        flag = prime(p);

        if( flag == 0 )
        {
            cout<<"\nWRONG INPUT\n";
            getch();
            exit(1);
        }

        cout<<"\nENTER ANOTHER PRIME NUMBER : \t";
        cin>>q;
        flag = prime(q);

        if( flag == 0 || p == q )
        {
            cout<<"\nWRONG INPUT\n";
            getch();
            exit(1);
        }

        cout<<"\nENTER MESSAGE:\n\n";
        fflush( stdin );
        cin>>msg;

        for( i = 0 ; msg[i] != NULL ; i++ )
        {
                m[i] = msg[i];
                n = p * q;
                t = (p-1) * (q-1);                                      // Euler quotient function
                ce();
        }


        cout<<"\nPOSSIBLE VALUES OF e AND d ARE\n";
        cout <<"e"<<"\t d"<<"\n";

        for( i = 0 ; i < j-1 ; i++ )
        {
            cout<<"\n"<<e[i]<<"\t"<<d[i];
            publickey();
            privatekey();
            encrypt();
            decrypt();
        }


}
int prime( long int pr )
{
        int i;
        j = sqrt( pr );
        for( i = 2 ; i <= j ; i++ )
        {
            if( pr % i == 0 )
            return 0;
        }
        return 1;
}



void ce()
{
        int k;
        k = 0;
        for( i = 2 ; i < t ; i++ )
        {
            if( t % i == 0 )
            continue;
            flag = prime(i);
            if( flag == 1 && i != p && i != q )
            {
                e[k] = i;
                flag = cd( e[k] );
                if( flag > 0 )
                {
                    d[k] = flag;
                    k++;
                }
                if( k == 99 )
                break;
            }
        }
}



long int cd( long int x )
{
        long int k = 1;
        while(1)
        {
            k = k + t;
            if( k % x == 0)
            return( k / x );
        }
}



void encrypt()
{
        long int pt,ct,key=e[0],k,len;
        i = 0;
        len = strlen( msg );

        while( i != len )
        {

            pt = m[i];

            if(pt > 95 && pt < 106)
            {
                pt = pt + 10 ;
            }

            else if( pt > 105 && pt < 116)
            {
                pt = pt - 10 ;
            }

            else if( pt > 115 && pt < 122)
            {
                pt = pt - 51;
            }

            k = 1;

            k = k * pt;


            temp[i] = k;

             if(k > 105 && k < 116)
            {
                ct = k - 10 ;
            }

            else if( k > 95 && k < 106)
            {
                ct = k + 10 ;
            }

            else if( k > 64 && pt < 71)
            {
                ct = k + 51;
            }

            en[i] = pt;
            i++;
        }

        en[i] = -1;
        cout<<"\n\nTHE ENCRYPTED MESSAGE IS:\n\n\t";
        for( i = 0 ; en[i] != -1 ; i++ )
        {
             cout<<en[i];
        }


}



void decrypt()
{
        long int pt,ct,key=d[0],k;
        i = 0;
        while( en[i] != -1 )
        {
            ct = temp[i];
            k = 1;

            k = k * ct;

             if(k > 105 && k < 116)
            {
                pt = k - 10 ;
            }

            else if( k > 95 && k < 106)
            {
                pt = k + 10 ;
            }

            else if( k > 64 && pt < 71)
            {
                pt = k + 51;
            }

            m[i] = pt;
            i++;
        }
           m[i] = -1;
           cout<<"\n\nTHE DECRYPTED MESSAGE IS\n\n\t";
           cout<<msg;

           cout<<"\n\n";
}
