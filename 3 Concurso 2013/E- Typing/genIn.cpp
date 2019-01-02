#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;

int main()
{
	freopen("typing.in","w",stdout);
	srand(time(NULL));
	int T = 10000;
	cout<<T<<endl;
	For(i, 0, T)
	{
		int size = (rand()%1000)+1;
		For(j, 0, size)
		{
			if (rand()%10 >= 7)
				cout<<" ";
			else
				cout<<char((rand()%26)+97);
		}
		cout<<endl;
	}
}
