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

int main()
{
	int T = 100;
	printf("%d\n", T);


	//random_device rd; // obtain a random number from hardware
    mt19937 eng(static_cast<unsigned int>(time(NULL))); // seed the generator
    uniform_int_distribution<int> distn(1, 100); // define the range
    uniform_int_distribution<int> distm(1, 11); // define the range
    vi v(100, 1);
	v[0] = 100;
	v[1] = 25;
	v[2] = 5;
	discrete_distribution<int> dista(v.begin(), v.end());


    



    //zdouble en = 0, em = 0;

	REP(k, T)
	{
		int n = distn(eng);
		int m = distm(eng);
		printf("%d %d\n", n, m);

		//en += (n / (double)T);
		//em += (m / (double)T);



		REP(i, n)
		{
			bool is_first = true;
			REP(j, m)
			{
				if(not is_first)
					printf(" ");  

				printf("%d", dista(eng));

				is_first = false;
			}
			printf("\n");
		}
	}



	return 0;
}