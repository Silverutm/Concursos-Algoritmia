#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll intervalo(int a, int b)//////////////////////////////////////////////ints
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

#define uno 1
#define dos 2
#define tres 3
#define unodos 4
#define unotres 5
#define dostres 6
#define unodostres 7

ll n[3], p1[3], p2[3], p3[3], f[3], t[3];
char e;
int caso = 2;		//pequenho
int subconjunto;
ll N, P1, P2, P3, F, T, T_ant;
int arriba, i;

ll tiempo()
{
	int s = subconjunto;
	ll r;
	if (s==1)		//todos bajan en el df, o escoger a f despues?
	{
		r = T_ant + intervalo(2,4);
		if (r>=F) F+=intervalo(2,4);
		return r;
	}

	if (s==2)	//todos bajan enmedio
	{
		
		if (e=='S')
		{
			r = T_ant + intervalo(2,4);
			if (r==F) F+=intervalo(2,4);
			return r;		
		}
		else
		{
			T_ant = max(T_ant, F);
			r = T_ant + intervalo(2,4);
			return r;
		}
	}

	if (s==3)
	{
		T_ant = max(T_ant, F);
		r = T_ant + intervalo(2,4);
		return r;
	}

	

}

char lo_que_sea()
{
	char e;
	//cout<<i<<" "<<arriba<<" "<<N<<"   -------\n";
	if (i+arriba>=N) e = 'B';
	else if (arriba==0) e = 'S';//S
	else
	{
		int z = rand()%2;
		if (z) e = 'B';
		else e='S';//S
	}
	return e;
}

char escoger_e()
{
	/*if (i+arriba>=n) e = 'B';
			else if (arriba==0) e = 'S';
			else
			{
				z = rand()%2;
				if (z) e = 'B';
				else e='S';
			}*/
	int s = subconjunto;
	char e;
	if (s==1)		//todos bajan en el df
	{
		e = lo_que_sea();
		//rand()%(F - T_ant +1  ) + T_ant;
		return e;
	}

	if (s==2)	//todos bajan enmedio
	{
		if (i<N/2) return 'S';
		return 'B';
	}
	if (s==3)
	{
		e = lo_que_sea();
		return e;
	}

	
}

int main()
{
	srand (time(NULL));
	int c=50;
	cout<<c<<"\n";
	//2147483647
	n[0]=10; n[1]=100; n[2]=150;
	p1[0]=p2[0]=p3[0]=100;	p1[1]=p2[1]=p3[1]=10000;	p1[2]=p2[2]=p3[2]=1000000000000LL; 
	f[0]=100; f[1]=1000; f[2]=10000;
	t[0]=100; t[1]=1000; t[2]=10000;
	string E; vector <ll> Tiempo;
	while(c--)
	{
		E.clear(); Tiempo.clear();
		do
		{
			N = rand() %( n[caso] - 6 + 1 )+ 6;
		}while (N&1);
		cout<<N<<"\n";

		if (caso==0)
		{
			P1 = rand() % p1[caso] + 1;
			P2 = rand() % p2[caso] + 1;
			P3 = rand() % p3[caso] + 1;		

			F = rand()%(60 - 40 + 1 ) + 40;
		}
		else if (caso==1)
		{
			P1 = rand() % p1[caso] + 1;
			P2 = rand() % p2[caso] + 1;
			P3 = rand() % p3[caso] + 1;

			F = rand()%(600 - 400 + 1 ) + 400;
		}
		else if (caso==2)
		{
			P1 = rango(9,12);		//cantidad de digitos
			P2 = rango(9,12);
			P3 = rango(9,12);

			F = rand()%(6000 - 4000 + 1 ) + 4000;
		}
		//cout<<P1<<" "<<P2<<" "P3<<" "<<F<<"\n";

		arriba = 0;
		int z;
		subconjunto = rand()%7+1;
		//cout<<subconjunto<<"\n";
		T_ant = 1;
		if (subconjunto<=3)
			for (i = 0; i < N; ++i)		//los posibles subconjuntos
			{
				e = escoger_e();

				if (e=='S') ++arriba;
				else --arriba;

				T = tiempo();
				
				T_ant = T;
				E.push_back(e); Tiempo.push_back(T);
			}
		else
		{
			if (subconjunto==4)
			{
				//cout<<"aqui\n";
				subconjunto = 1;
				for (i = 0; i < N/4; ++i)		//los posibles subconjuntos
				{
					e = 'S';				
					
					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
				//cout<<i<<"  ..\n";
				ll k = N;
				N = N - N/4*2;
				for (i=0 ; i < N; ++i)		//los posibles subconjuntos
				{
					e = escoger_e();

					if (e=='S') ++arriba;
					else --arriba;

					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
				//cout<<i<<"  ..\n";
				subconjunto = 3;
				i = k/4+i;
				N=k;
				for (; i < N; ++i)		//los posibles subconjuntos
				{
					e = 'B';				
					
					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
				//cout<<i<<"  ..\n";
			}

			else if (subconjunto==5)
			{
				N=N/2;
				subconjunto = 1;
				for (i = 0; i < N; ++i)		//los posibles subconjuntos
				{
					e = escoger_e();

					if (e=='S') ++arriba;
					else --arriba;

					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
				subconjunto = 3;
				for (i = 0; i < N; ++i)		//los posibles subconjuntos
				{
					e = escoger_e();

					if (e=='S') ++arriba;
					else --arriba;

					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
			}

			else if (subconjunto==6)
			{				
				subconjunto = 1;				
				for (i = 0; i < N/4; ++i)		//los posibles subconjuntos
				{
					e = 'S';				
					++arriba;
					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
				subconjunto = 3;
				for (; i < N; ++i)		//los posibles subconjuntos
				{
					e = escoger_e();

					if (e=='S') ++arriba;
					else --arriba;

					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
			}

			else if (subconjunto==7)
			{				
				
				
				ll k = N - N*3/4;
				ll k2 = N*3/4;
				N=k;
				subconjunto = 1;				
				for (i = 0; i < N; ++i)		//los posibles subconjuntos
				{
					e = escoger_e();

					if (e=='S') ++arriba;
					else --arriba;

					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}			
				N=k2;	
				for (i = 0; i < N/4; ++i)		//los posibles subconjuntos
				{
					e = 'S';				
					++arriba;
					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
				subconjunto = 3;
				for (; i < N; ++i)		//los posibles subconjuntos
				{
					e = escoger_e();

					if (e=='S') ++arriba;
					else --arriba;

					T = tiempo();
					
					T_ant = T;
					E.push_back(e); Tiempo.push_back(T);
				}
			}
		}

		cout<<P1<<" "<<P2<<" "<<P3<<" "<<F<<"\n";
		//cout<<e<<" "<<T<<"\n";
		//		E.push_back(e); Tiempo.push_back(T);
		for (i = 0; i < E.size(); ++i)
		{
			cout<<E[i]<<" "<<Tiempo[i]<<"\n";
		}
		if (arriba) return 0;
	}  	
	return 0;
}