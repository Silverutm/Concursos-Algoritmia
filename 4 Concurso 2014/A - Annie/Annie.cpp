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

int casos, q;
ii annie, campeon;

int distancia_squared(ii u, ii v)
{
    return (u.first-v.first)*(u.first-v.first) + (u.second-v.second)*(u.second-v.second);
}

void querea()
{
    scanf("%d %d", &campeon.first, &campeon.second);
    int dis_squ = distancia_squared(annie, campeon);
    if( dis_squ <= 250000 )
        printf("FULL COMBO\n");
    else
        printf("OUTPLAYED\n");

}

void solve()
{
    scanf("%d %d", &annie.first, &annie.second);
    scanf("%d", &q);
    REP(i, q)
        querea();
}

int main()
{
    freopen("Annie.in", "r", stdin);
    freopen("Annie.out", "w", stdout);
    scanf("%d", &casos);
	while(casos--)
		solve();
	return 0;
}
