#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair
#define EPS 10e-8

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

struct point{ double x, y;
	point(){ x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if(fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y; } 
		
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
};

struct vec { double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {} };
	
vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

point pivot(0, 0);

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) { 
	return cross(toVec(p, q), toVec(p, r)) > 0;//cambiar si se aceptan colineales 
}

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; 
}

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2 .y);
}

bool angleCmp(point a, point b) {
	if(collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
		
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P ) {
	int i, j, n = (int) P.size();
	if(n <= 3) {
		if(!(P[0] == P[n - 1])) P.push_back(P[0]);
		return P; }
		
	//PO = indice del pivote
	int PO = 0;
	for(i = 1; i < n; i++)
		if(P[i].y < P[PO].y || (P[i].y == P[PO].y && P[i].x > P[PO].x))
			PO = i;
			
	point temp = P[0]; P[0] = P[PO]; P[PO] = temp; //cambia el pivote al principio
	
	pivot = P[0];
	sort(P.begin() + 1, P.end(), angleCmp);
	
	vector<point> S;

	S.push_back(P[n - 1]); S.push_back(P[0]); S.push_back(P[1]);
	i = 2;
	while(i < n) {
		j = (int) S.size() - 1;
		if(ccw(S[j - 1], S[j], P[i])) S.push_back(P[i++]);
		else S.pop_back(); }
	
	return S;
}	

bool myccw(point A, point B, point C)
{
	return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x) >= 0;
}


bool Dentro(point Q, vector <point> p)
{
	bool sgn = myccw(Q, p[0], p[1]), ok = true;
	int n = p.size();
	For(i, 1, n)
		if (myccw(Q, p[i], p[(i+1)%n]) != sgn)
		{
			ok = false;
			break;
		}

	return ok;
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	srand(time(NULL));

	int tt = 90;
	printf("%d\n", tt);
	while (tt--)
	{
		int n = (rand()%98)+3;
		vector <point> P(n);
		For(i, 0, n)
			P[i] = point(rand()%101, rand()%101);
		P = CH(P);

		point Q;
		while (true)
		{
			Q = point(rand()%100, rand()%100);
			bool ok = true;
			For(i, 0, (int)P.size())
			{
				point A = P[i], B = P[(i+1)%(int)P.size()];
				int minx = min(A.x, B.x), maxx = max(A.x, B.x);
				int miny = min(A.y, B.y), maxy = max(A.y, B.y);
				if (collinear(Q, A, B) and minx <= Q.x and Q.x <= maxx and miny <= Q.y and Q.y <= maxy)
					ok = false;
			}

			if (ok)
				break;
		}

		printf("%d\n", (int)P.size());
		For(i, 0, (int)P.size())
			printf("%.0f %.0f\n", P[i].x, P[i].y);
		printf("%.0f %.0f\n", Q.x, Q.y);
	}

	return 0;
}