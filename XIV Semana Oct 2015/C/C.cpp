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



bool is_valid(ii v, int n, int m)
{
	return v.X < n and v.X >= 0 and v.Y < m and v.Y >= 0;
}

int bfs(vector<string> &b, ii s, ii t, int n, int m)
{
	int ni[] = {-2, -1, +1, +2, +2, +1, -1, -2};
	int nj[] = {+1, +2, +2, +1, -1, -2, -2, -1};
	vector<vector<int> > d(n+1, vi(m+1, INF));

	queue<ii> cola;

	//DEBUG(s.X);
	//DEBUGLN(s.Y);
	//DEBUG(t.X);
	//DEBUGLN(t.Y);

	cola.push(s);
	d[s.X][s.Y] = 0;

	while(not cola.empty())
	{
		ii u = cola.front();
		cola.pop();

		//DEBUG(u.X);
		//DEBUGLN(u.Y);

		REP(k, 8)
		{
			ii v = ii(u.X + ni[k], u.Y + nj[k]);
			//DEBUG(v.X);
			//DEBUGLN(v.Y);
			if(is_valid(v, n, m ) and b[v.X][v.Y] == '*' and d[u.X][u.Y] + 1 < d[v.X][v.Y] )
			{
				cola.push(v);
				d[v.X][v.Y] = d[u.X][u.Y] + 1;

			}
		}

	}

	// REP(i, n)
	// {
	// 	REP(j, m)
	// 	{
	// 		fprintf(stderr, "%2d", ( (d[i][j] < INF)?d[i][j]: -1));
	// 	}
	// 	fprintf(stderr, "\n");
	// }


	return d[t.X][t.Y];
}

void solve()
{
	int n, m;

	cin >> n >> m;

	vector<string> board(n, string(m, ' '));
	//DEBUG(n);
	//DEBUGLN(m);

	ii s, t;

	REP(i, n)
	{
		REP(j, m)
		{
			cin >> board[i][j];
			if(board[i][j] == 'c')
				s = ii(i, j);
		}
	}

	cin >> t.X >> t.Y;

	t = ii( n-t.X ,t.Y-1 );

	int dist = bfs(board, s, t, n, m);

	if(dist < INF)
		cout << dist << '\n';
	else
		cout << "-1\n";

}

int main()
{
	int T;
	cin >> T;

	REP(i, T)
		solve();

	return 0;
}