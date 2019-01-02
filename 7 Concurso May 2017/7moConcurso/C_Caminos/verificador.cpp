#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[3], t[3];

int main()
{	
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

			freopen(archivo, "r", stdin);
			int c=100;
			cin>>c;
			
			ll M,N, T;
			while(c--)
			{

				cin>>M>>N>>T;
				if (M+N>m[caso] or T > t[caso])
				{
					cout<<"Error\n";
					fclose(stdin);
					return 0;
				}
			}
			fclose(stdin);

		}
	}
	return 0;
}