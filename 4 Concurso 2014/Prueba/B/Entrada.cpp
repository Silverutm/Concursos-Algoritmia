#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	printf("999\n");
	for(int i = 0; i < 999; ++i)
	{
		printf("%d\n", (rand()%32768) + 1);
	}
	return 0;
}