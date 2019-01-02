#include <iostream>
#include <algorithm>
using namespace std;
int V;
int AdjMat[160][160];
void floyd()
{
	for (int k = 0; k < V; k++) // remember that loop order is k->i->j
	for (int i = 0; i < V; i++)
	for (int j = 0; j < V; j++)
	AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
}

int main()
{
	int k, a, b, q;
	cin>>k;
	while (k--)
	{
		cin>>V;
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				cin>>AdjMat[i][j];
		floyd();
		cin>>q;
		while (q--)
		{
			cin>>a>>b;
			a; b;
			cout<<AdjMat[a][b]<<endl;
		}
	}
	return 0;
}