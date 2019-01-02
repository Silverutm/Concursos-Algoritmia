#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll intervalo(int a, int b)
{
	return rand()%(b-a+1) + a;		//un numero en [a,b]
}
int m[3], n[3];

int main()
{
	srand (time(NULL));
	m[0]=100; m[1]=500; m[2]=1000;
	n[0]=500; n[1]=1000; n[2]=10000;
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
			int c=20;
			cout<<c<<"\n";
			
			ll M, N, X, Y;
			while(c--)
			{
				M = intervalo(2,m[caso]);
				N = intervalo(2, n[caso]);
				N= min(N, M*(M-1)/2);
				cout<<M<<" "<<N<<"\n";
				while(N--)
				{
					X = intervalo(1,M);
					do{Y = intervalo(1,M);}
					while (X==Y);
					cout<<X<<" "<<Y<<"\n";
				}
				cout<<"\n";	
			}
			
			fclose(stdout);

		}
	}
	
	return 0;
}