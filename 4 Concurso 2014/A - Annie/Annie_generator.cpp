#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<bool> vb;

#define N 20
#define Q 50
#define MAX_CORD 9000

int main()
{
    freopen("Annie.in", "w", stdout);
    srand(time(NULL));
    printf("20\n");
    REP(i, N)
    {
        int q = 3+(rand()%Q);
        int x = rand()%MAX_CORD;
        int y = rand()%MAX_CORD;
        printf("%d %d %d\n", x, y, q);
        REP(i, q)
        {
            if(i % 5 == 0)
                printf("%d %d\n", x+(rand()%150), y+(rand()%150) );
            else
                printf("%d %d\n", rand()%MAX_CORD, rand()%MAX_CORD);
        }
    }
    return 0;
}
