#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll intervalo(int a, int b)
{
	return rand()%(b-a+1) + a;		//un numero en [a,b]
}
int f[3], cc[3];

set <ll> conjunto;
int main()
{
	srand (time(NULL));
	f[0]=40; f[1]=90; f[2]=1000000;
	cc[0]=30;cc[1]=60; cc[2]=100000;
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
			int c=cc[caso];
			cout<<c<<"\n";
			conjunto.clear();
			ll N;
			while(c--)
			{	
				do{N = intervalo(1, f[caso]);}
				while(conjunto.find(N)!=conjunto.end());
				conjunto.insert(N);
				cout<<N<<"\n";
			}
			
			fclose(stdout);

		}
	}
	
	return 0;
}