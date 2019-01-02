#include <iostream>

#include <algorithm>

using namespace std;



int mcd(int a, int b)

{

    b==0 ? a:mcd(b,a%b);

}



int main()

{

    int t,n,alma, cont,tt,pot,aux;

    cin>>t;

    for(tt=1;tt<=t;tt++)

    {

        cin>>n;

        alma=n;

        cont=0;

        pot=1;

        while(mcd(alma,2)==2)

        {

            alma=alma/2;

            cont++;

            pot=pot*2;

        }

        alma=n/pot;

        cout<<"Caso #"<<tt<<": (2^"<<cont<<")*"<<alma<<endl;

    }

    return 0;

}