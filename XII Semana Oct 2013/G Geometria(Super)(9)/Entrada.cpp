#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	printf("21\n");
	for(int i = 0; i < 20000; ++i)
	{
		printf("%d\n", (rand()%10000) + 1);
	}
	return 0;
}