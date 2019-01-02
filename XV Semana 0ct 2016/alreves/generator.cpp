#include <bits/stdc++.h>
using namespace std;
//look at my code my code is amazing
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FOREACH(it, a) for (typeof(a.begin()) it = (a).begin(); it != (a).end(); it++)
#define ROF(i, a, b) for (int i = int(a); i >= int(b); i--)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define ALL(x) x.begin(), x.end()
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second
#define EPS 1e-9
#define DEBUG(x)   cerr << #x << ": " << x << " "
#define DEBUGLN(x) cerr << #x << ": " << x << " \n"
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<bool> vb;
//ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
//cin.tie(NULL); cout.tie(NULL);

int main()
{
	random_device rd;
	mt19937 gen(rd());

	const int N       = 10000;
	const int A_B_GEQ_LITTLE = 1;
	const int A_B_LEQ_LITTLE = 200;
	const int A_B_GEQ_MEDIUM = 1;
	const int A_B_LEQ_MEDIUM = 500;
	const int A_B_GEQ_BIG = 1;
	const int A_B_LEQ_BIG = 1000000;

	// little case
	freopen("little.in","w",stdout);
	auto dist = uniform_int_distribution<int>(A_B_GEQ_LITTLE, A_B_LEQ_LITTLE);
	cout << N << '\n';
	REP(i, N)
	{
		int a = dist(gen);
		int b = dist(gen);
		if(a > b)
			swap(a, b);
		cout << a << ' ' << b << '\n';
	}

	// medium case
	freopen("medium.in","w",stdout);
	dist = uniform_int_distribution<int>(A_B_GEQ_MEDIUM, A_B_LEQ_MEDIUM);
	cout << N << '\n';
	REP(i, N)
	{
		int a = dist(gen);
		int b = dist(gen);
		if(a > b)
			swap(a, b);
		cout << a << ' ' << b << '\n';
	}

	// big case
	freopen("big.in","w",stdout);
	dist = uniform_int_distribution<int>(A_B_GEQ_BIG, A_B_LEQ_BIG);
	cout << N << '\n';
	REP(i, N)
	{
		int a = dist(gen);
		int b = dist(gen);
		if(a > b)
			swap(a, b);
		cout << a << ' ' << b << '\n';
	}

	return 0;
}
