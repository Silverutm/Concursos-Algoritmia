#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi Lista[1009];
int n, m, t, a, b;
bitset<1009> visitado;

void buscar(int u)
{
	visitado[u] = true;

	for (auto v: Lista[u])
	{
		if (visitado[v]) continue;

		buscar(v);
	}
}

int main()
{
	
	char entrada[] = "C1.in", salida[] = "C1.outM";
	for (int caso = 0; caso < 3; ++caso)
	{
		for (char ci = '0'; ci <= '9'; ++ci)
		{
			if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
			else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M';}
			else {entrada[0] = 'G'; salida[0] = 'G';}
			entrada[1] = ci; salida[1] = ci;

			freopen(entrada, "r", stdin);
			freopen(salida, "w", stdout);

			cin>>t;
			while (t--)
			{
				cin>>m>>n;
				swap(m,n);
				for (int i = 1; i <= n; ++i)
					Lista[i].clear();
				visitado.reset();

				while(m--)
				{
					cin>>a>>b;
					Lista[a].push_back(b);
				}

				buscar(1);
				if (visitado[n])
					printf("Corre, Schnitzel.\n");
				else printf("No te molestes.\n");
			}

			fclose(stdin);
			fclose(stdout);
		}
	}
	return 0;
}