#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("DataLoL.in","w",stdout);
	int a = 100,b;
	cout<<200<<endl;
	a--;
	cout<<450<<" "<<400<<" "<<1<<" "<<9<<endl;
	while(a--)
	{
		for(int i=0;i<2;i++)
		{
			cout<<rand()%500 + 1<<" ";
		}
		b = rand()%10 + 1;
		cout<<b<<" ";
		cout<<rand()%(11-b) + b;
		cout<<endl;
	}
	//cout<<1<<endl;
	int v[4];
	for(int i = 0;i < 100; i++)
	{
		v[0]=rand()%500 +1;
		v[1]=rand()%500 + 1;
		v[2]=rand()%10 + 1;
		v[3]=rand()%(11-v[2]) + v[2];
		while((v[0] * (v[3] - v[2])) <= (v[1]*v[3]))
		{
			v[0] = rand()%500 + 1;
			v[1] = rand()%500 + 1;
			v[2]=rand()%10 + 1;
			v[3]=rand()%(11-v[2]) + v[2];
		}
		cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
	}
	cout<<"ya"<<endl;
	return 0;
}