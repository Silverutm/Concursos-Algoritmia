#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
//	freopen("DataLoL.out","w",stdout);
//	freopen("DataLoL.in","r",stdin);
	int n,c1,c2,T,C;
	cin>>n;
	while(n--)
	{
		cin>>c1>>c2>>T>>C;
		c2 *= C;
		c1 = (C - T)*c1;
		if(c1 > c2)
		{
			cout<<"Se muere"<<endl;
		}
		else
		{
			cout<<"Se salva"<<endl;
		}
	}
}
