#include <iostream>
#include <cstring>
using namespace std;
char matriz[200][200], m2[200][200];
int vecinos(int i, int j)
{
	int cant =0;
	cant += matriz[i-1][j]=='*';
	cant += matriz[i+1][j]=='*';
	cant += matriz[i][j-1]=='*';
	cant += matriz[i][j+1]=='*';
	cant += matriz[i-1][j-1]=='*';
	cant += matriz[i-1][j+1]=='*';
	cant += matriz[i+1][j-1]=='*';
	cant += matriz[i+1][j+1]=='*';
	return cant;
}
int main()
{
	int n, t, f, c;
	cin>>n;
	while (n--)
	{
		//memset(matriz, 0, sizeof matriz);
		cin>>f>>c;
		
		for (int i = 0; i <= f+1; ++i)
				for (int j = 0; j <= c+1; ++j)
					m2[i][j]=matriz[i][j]='.';

		
		for (int i = 1; i <= f; ++i)
			for (int j = 1; j <= c; ++j)
				cin>>matriz[i][j];
		/*for (int i = 1; i <= f; ++i)
				for (int j = 1; j <= c; ++j, cout<<endl)
					cout<<matriz[i][j];*/
		//return 0;
		cin>>t;
		for (int w = 0; w < t; ++w)
		{
			for (int i = 1; i <= f; ++i)
				for (int j = 1; j <= c; ++j)
				{
					int k=  vecinos(i, j);
					m2[i][j]=matriz[i][j];
					if (matriz[i][j]=='*')
					{
						if (k<2 or k>3) m2[i][j]='.';
					}
					else if (k==3) m2[i][j]='*';
				}

			for (int i = 1; i <= f; ++i)
				for (int j = 1; j <= c; ++j)
					matriz[i][j]=m2[i][j];
		}
		for (int i = 1; i <= f; ++i, cout<<endl)
				for (int j = 1; j <= c; ++j)
					cout<<matriz[i][j];
	}
	return 0;
}