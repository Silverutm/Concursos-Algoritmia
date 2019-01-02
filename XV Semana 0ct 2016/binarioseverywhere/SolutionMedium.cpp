#include <iostream>
using namespace std;
#define tam 205
int solucion[tam], eval[tam];
int n, a, p, x, c, cant;

int posible()
{
	bool res = true;
	for (int i = 0; i < p; ++i)
		res= res and (eval[i]== solucion[i] or  solucion[i]==-1);
	return res;
}

int main()
{
	cin>>n;
	while (n--)
	{
		cant =0;
		cin>>a>>p;
		for (int i = 0; i < p; ++i)
			cin>>solucion[i];
		for (int i = 1; i < a; ++i)
			for (int j = 0; j < p; ++j)
			{
				cin>>x;
				if (solucion[j]!=x) solucion[j]=-1;
			}
		cin>>c;
		for (int i = 0; i < c; ++i)
		{
			for (int j = 0; j < p; ++j)
				cin>>eval[j];
			cant += posible();
		}
		cout<<cant<<endl;
	}
	return 0;
}