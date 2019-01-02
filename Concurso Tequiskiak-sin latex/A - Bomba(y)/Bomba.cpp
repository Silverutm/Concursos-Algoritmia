#include <iostream>

#define For(i, a, b) for(int i=a; i<b; ++i)

using namespace std;

int dist(int x1, int y1, int z1, int x2, int y2, int z2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}

int main()
{
	int C;
	cin>>C;

	For(i, 0, C)
	{
		int P, Tx, Ty, Tz, total = 0;
		cin>>P>>Tx>>Ty>>Tz;

		int N;
		cin>>N;

		For(j, 0, N)
		{
			int x, y, z;
			cin>>x>>y>>z;
			if (dist(x, y, z, Tx, Ty, Tz) <= P*P)
			{
				//cout<<x<<" "<<y<<" "<<z<<endl;
				total++;
			}
		}

		cout<<total<<endl;
	}

	return 0;
}