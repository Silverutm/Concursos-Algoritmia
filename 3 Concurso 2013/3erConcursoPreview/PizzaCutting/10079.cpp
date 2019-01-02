#include<iostream>
#include<fstream>
    using namespace std;

int main()
{
    long long quesos=0,n;
    ifstream entradas("entradas10079.txt");
    ofstream archi("salidas10079.txt");
    entradas.is_open();
    entradas>>n;
    while(n>=0)
    {

        quesos=n*(n+1)/2+1;
        archi<<quesos<<endl;
        entradas>>n;

    }

    return 0;
}
