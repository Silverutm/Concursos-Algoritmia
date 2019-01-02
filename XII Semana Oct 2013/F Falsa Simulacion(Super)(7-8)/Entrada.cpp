#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	for (int i = 0; i < 10000; ++i)
	{
		int j = (rand()%4)+1;
		if(j == 1)
			printf("R %d %d\n", (rand()%1234)+1, (rand()%1234)+1 );
		else if(j == 2)
			printf("C %d %d\n", (rand()%5678)+1, (rand()%5678)+1 );
		else if(j == 3)
			printf("Q %d %d\n", (rand()%1234)+1, (rand()%5678)+1 );
		else if(j == 4)
			printf("W %d\n", (rand()%(1234*5678))+1 );
	}
	return 0;
}