#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand (time(NULL));
	char matriz[200][200];
	for (int i = 0; i < 200; ++i)
	{
		for (int j = 0; j < 200; ++j)
		{
			matriz[i][j]='.';
		}
	}
	int f, c, x;
	cin>>f>>c;
	//cout<<f<<" "<<c<<endl;
	cout<<f+10<<" "<<c+75<<endl;
	for (int i = 0; i < f; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin>>x;
			if (x) matriz[i+5][j+70]='*';
			//else cout<<".";
		}
		//cout<<endl;
	}
	for (int i = 0; i < f+10; ++i)
	{
		for (int j = 0; j < c+75; ++j)
		{
			cout<<matriz[i][j];
		}
		cout<<endl;
	}
	//cout<<rand()%50<<endl;
	cout<<100<<endl;
	return 0;
}