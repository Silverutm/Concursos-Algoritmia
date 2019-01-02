#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll intervalo(int a, int b)//////////////ints
{
	return rand()%(b-a+1) + a;		//un numero en [a,b]
}

ll rango(int a, int b)		//un numero con esa cantidad de digitos////////////////////longs
{
	ll n = rand()%9 + 1;

	int cantidad = intervalo(a, b);
	--cantidad;		//ya tiene un digito

	for (int i = 0; i < cantidad; ++i)
	{
		n = 10*n + rand()%10;
	}
	return n;
}

int m[3], t[3];

int main()
{
	srand (time(NULL));	
	t[0]=100; t[1]=1000; t[2]=10000;
    m[0]=4; m[1]=8; m[2]=15;
	char archivo[] = "C1.in";
	for (int caso = 0; caso < 3; ++caso)
	{
		for (char i = '0'; i <= '9'; ++i)
		{
			if (caso==0) archivo[0] = 'C';
			else if (caso==1) archivo[0] = 'M';
			else archivo[0] = 'G';
			archivo[1] = i;

			freopen(archivo, "w", stdout);

			
/////////////////////////////////////////						
			cout<<t[caso]<<"\n";
			int w = t[caso];
			ll a, b;
			while(w--)
			{
				a = rango(1,m[caso]);
				b = rango(1, m[caso]);				
				cout<<a<<" "<<b<<"\n";
			}
//////////////////////////////////////////






			fclose(stdout);
		}
	}
	
	return 0;
}