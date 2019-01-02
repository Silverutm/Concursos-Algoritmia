#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int m[3];

int intervalo(int, int);
 
int main()
{
    srand (time(NULL));
    m[0]=10; m[1]=15; m[2]=100000;
    char archivo[] = "C1.inR";
    
    for (int caso = 0; caso < 3; ++caso)
    {
        for (char i = '0'; i <= '9'; ++i)
        {
            if (caso==0) archivo[0] = 'C';
            else if (caso==1) archivo[0] = 'M';
            else archivo[0] = 'G';
            archivo[1] = i;
 
            freopen(archivo, "w", stdout);
 
            int T;
            if (caso == 0 or caso == 1)
                T=10;
            else 
                T=1000;
            cout<<T<<endl;
            while(T--)
                cout<<intervalo(1,m[caso])<<endl;
            
            fclose(stdout);
        }
    }
    return 0;
}
int intervalo(int a, int b)//////////////ints
{
    return rand()%(b-a+1) + a;      //un numero en [a,b]
}