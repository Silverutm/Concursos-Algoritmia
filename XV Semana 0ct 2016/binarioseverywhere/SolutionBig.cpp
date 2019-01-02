#include <iostream>
using namespace std;
#define tam 505
int solucion[tam], eval[tam];
int n, a, p, x, c, cant;

int posible()
{
	int res = 1;
	for (int i = 0; i < p; ++i)
		res= res and (eval[i]== solucion[i] or  solucion[i]==-1);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
	cin.tie(NULL); cout.tie(NULL);
	
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
		int res=0;
		for (int i = 0; i < c; ++i)
		{
			for (int j = 0; j < p; ++j)
				cin>>eval[j];
			cant += posible();
			//for (int j = 0; j < p; ++j)
			//	if (solucion[j]!=-1)
			//		res +=abs(solucion[j]-eval[j]);
			//cout<<res<<"  ."<<endl;
		}
		cout<<cant<<'\n';
	}
	return 0;
}