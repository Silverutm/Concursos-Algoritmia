#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, p1, p2, p3, f, t, c1,c2,c3;
char e;

int main()
{
	int c;	

	cin>>c;
	while (c--)
	{
		cin>>n;
		cin>>p1>>p2>>p3>>f;
		c1= c2=c3=0;
		for (int i = 0; i < n; ++i)		
		{
			cin>>e>>t;
			if (e=='S')
			{
				if (t > f)
					++c3;
			}
			else			
				if (t<f) ++c1;			
		}
		c2 = n/2 - c1 - c3;
		cout<<p1*c1 + p2*c2 + p3*c3<<"\n";
	}
	return 0;
}