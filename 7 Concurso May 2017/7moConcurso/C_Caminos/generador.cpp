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
	m[0]=10; m[1]=15; m[2]=50;
	t[0]=50; t[1]=100; t[2]=100;
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

			
			
			int c=100;
			cout<<c<<"\n";
			
			ll M,N, T;
			while(c--)
			{
				M = intervalo(1,m[caso]-1);
				N = intervalo(1, m[caso]- M);
				T = intervalo(1,t[caso]);
				cout<<M<<" "<<N<<" "<<T<<"\n";
			}






			fclose(stdout);
		}
	}
	
	return 0;
}