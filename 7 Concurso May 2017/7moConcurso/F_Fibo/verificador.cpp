#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f[3], cc[3];

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

			freopen(archivo, "r", stdin);			
			int c;
			cin>>c;
			if (c>cc[caso])
			{
					cout<<"Error\n";
					fclose(stdin);
					return 0;
			}
			
			ll N;
			while(c--)
			{					
				cin>>N;
				if (N>f[caso])
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