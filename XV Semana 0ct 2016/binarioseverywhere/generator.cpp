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

	const int N       = 100;
	const int A_P_C_GEQ_LITTLE = 1;
	const int A_P_C_LEQ_LITTLE = 100;
	const int A_P_C_GEQ_MEDIUM = 1;
	const int A_P_C_LEQ_MEDIUM = 200;
	const int A_P_C_GEQ_BIG = 1;
	const int A_P_C_LEQ_BIG = 500;

	// little case
	freopen("little.in","w",stdout);
	auto dist = uniform_int_distribution<int>(A_P_C_GEQ_LITTLE, A_P_C_LEQ_LITTLE);
	discrete_distribution<int> dist2 {1, 7};

	cout << N << '\n';

	REP(caso, N)
	{
		int a = dist(gen);
		int p = dist(gen);
		int c = dist(gen);

		cout << a << ' ' << p << '\n';
		REP(i, a)
		{
			REP(j, p)
			{
				if(j) 
					cout << ' ';
				cout <<  dist2(gen);
			}
			cout << '\n';
		}
		cout << c << '\n';
		REP(i, c)
		{
			REP(j, p)
			{
				if(j) 
					cout << ' ';
				cout <<  dist2(gen);
			}
			cout << '\n';
		}
	}

	// medium case
	freopen("medium.in","w",stdout);
	dist = uniform_int_distribution<int>(A_P_C_GEQ_MEDIUM, A_P_C_LEQ_MEDIUM);
	cout << N << '\n';
	REP(caso, N)
	{
		int a = dist(gen);
		int p = dist(gen);
		int c = dist(gen);

		cout << a << ' ' << p << '\n';
		REP(i, a)
		{
			REP(j, p)
			{
				if(j) 
					cout << ' ';
				cout <<  dist2(gen);
			}
			cout << '\n';
		}
		cout << c << '\n';
		REP(i, c)
		{
			REP(j, p)
			{
				if(j) 
					cout << ' ';
				cout <<  dist2(gen);
			}
			cout << '\n';
		}
	}

	// big case
	freopen("big.in","w",stdout);
	dist = uniform_int_distribution<int>(A_P_C_GEQ_BIG, A_P_C_LEQ_BIG);
	cout << N << '\n';
	REP(caso, N)
	{
		int a = dist(gen);
		int p = dist(gen);
		int c = dist(gen);

		cout << a << ' ' << p << '\n';
		REP(i, a)
		{
			REP(j, p)
			{
				if(j) 
					cout << ' ';
				cout <<  dist2(gen);
			}
			cout << '\n';
		}
		cout << c << '\n';
		REP(i, c)
		{
			REP(j, p)
			{
				if(j) 
					cout << ' ';
				cout <<  dist2(gen);
			}
			cout << '\n';
		}
	}

	return 0;
}
