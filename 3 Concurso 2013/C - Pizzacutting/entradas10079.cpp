#include<iostream>
#include<fstream>
#include<stdlib.h>
    using namespace std;

int main()
{
    ofstream archi("entradas10079.txt");
    if(archi.is_open())
    {
        for (long i=0;i<=10;i++)
        {
            archi<<0<<endl<<1<<endl<<2<<endl<<5<<endl<<10<<endl;
            archi<<4295*rand()%1000000+rand()<<endl;
        }
    }
    archi<<-1;
    return 0;
}
