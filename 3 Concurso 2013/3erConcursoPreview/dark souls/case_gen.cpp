#include<iostream>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	int n,m,x,y,f,e;
	
	map<int,char> mapa;
	mapa[0] = 'U';
	mapa[1] = 'D';
	mapa[2] = 'L';
	mapa[3] = 'R';
	
	cout<<100<<endl;
	
	for(int i=0;i<100;i++)
	{
		do
		{
			n = rand()%30;
			m = rand()%30;
			if(n*m)
			{
				f = rand()%(n*m/3);
				e = rand()%(n*m/3);
			}
		}while(!(n*m));
		
		cout<<n<<" "<<m<<endl<<f<<" "<<e<<endl;
		
		for(int j=0;j<f+e;j++)
		{
			x = rand()%n;
			y = rand()%m;
			cout<<x<<" "<<y<<" "<<mapa[rand()%4]<<endl;
		}
	}
	
	return 0;
}
