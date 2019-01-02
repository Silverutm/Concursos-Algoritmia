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

char pieza(int x)
{
	switch(x)
	{
		case 0:
			return '*';
		case 1:
			return 'q';
		case 2:
			return 'k';
		case 3:
			return 'b';
		case 4:
			return 't';
		case 5:
			return 'p';
		default:
			return '*';
	}
}

int main()
{
	int T = 90;
	printf("%d\n", T);


	//random_device rd; // obtain a random number from hardware
    mt19937 eng(static_cast<unsigned int>(time(NULL))); // seed the generator
    uniform_int_distribution<int> distn(1, 100); // define the range
    uniform_int_distribution<int> distm(1, 100); // define the range
    vi v(6, 1);
	v[0] = 20;
	discrete_distribution<int> dista(v.begin(), v.end());


    



    //zdouble en = 0, em = 0;

	REP(k, T)
	{
		int n = distn(eng);
		int m = distm(eng);
		printf("%d %d\n", n, m);

		//en += (n / (double)T);
		//em += (m / (double)T);


		uniform_int_distribution<int> disti(1, n); 
		uniform_int_distribution<int> distj(1, m); 

		ii s = ii(disti(eng), distj(eng));
		ii t = ii(disti(eng), distj(eng));

		s.X--;
		s.Y--;

		REP(i, n)
		{
			REP(j, m)
			{ 
				if(s.X == i and s.Y == j)
					printf("c");
				else
					printf("%c", pieza(dista(eng)));
			}
			printf("\n");
		}
		printf("%d %d\n", t.X, t.Y);
	}



	return 0;
}