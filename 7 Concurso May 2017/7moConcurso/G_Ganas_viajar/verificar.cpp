#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n[3], p1[3], p2[3], p3[3], f[3], t[3];
char e;
int caso = 2;		//pequenho
ll N, P1, P2, P3, F, T, T_ant, arriba;

int main()
{
	n[0]=10; n[1]=100; n[2]=150;
	p1[0]=p2[0]=p3[0]=100;	p1[1]=p2[1]=p3[1]=10000;	p1[2]=p2[2]=p3[2]=1000000000000LL; 
	f[0]=100; f[1]=1000; f[2]=10000;
	t[0]=100; t[1]=1000; t[2]=10000;

	ll c;
	cin>>c;
	if (c>50)
	{
		cout<<"Error\n";
		return 0;
	}

	for (int j = 0; j < c; ++j)	
	{
		cin>>N;
		int sub=0;
		T_ant=0;
		//cin>>sub;
		if (N>n[caso])
		{
			cout<<sub<<j<<"\n"<<"Error 1\n";
			return 0;
		}
		cin>>P1>> P2>> P3>> F;
		if (P1>p1[caso] or P2>p1[caso] or P3>p1[caso] or F>f[caso])
		{
			cout<<sub<<j<<"\n"<<"Error 2\n";
			return 0;
		}
		char e;
		ll T;	
		for (int i = 0; i < N; ++i)
		{
			cin>>e>>T;
			if (T>t[caso])
			{
				cout<<sub<<j<<"\n"<<"Error 3\n";
				return 0;
			}
			if (T<=T_ant or T==F)
			{
				cout<<sub<<j<<"\n"<<"Error 6\n";
				return 0;
			}
			if (e=='S') ++arriba;
			else --arriba;

			if (arriba<0)
			{
				cout<<sub<<j<<"\n"<<"Error 4\n";
				return 0;
			}
			T_ant=T;
		}
		if (arriba)
		{
			cout<<sub<<j<<"\n"<<"Error 5\n";
			return 0;
		}
	}
	return 0;
}