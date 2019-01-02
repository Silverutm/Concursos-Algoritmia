#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll intervalo(int a, int b, int origen)
{
	if (b==0) return b;
	if (b<a) 
	{
		cout<<"Error---\n";
		cout<<a<<" "<<b<<" "<<origen<<"\n";
		exit (0);
	}
	return rand()%(b-a+1) + a;		//un numero en [a,b]
}
ll r[3], h[3];
double H, K, X, Y, R, Z, XT;
double E;

void revisa()
{
	if (E<0)
	{
		cout<<"Error\n";
		printf("%lf %lf %lf\n",R, H, X );
		//cout<<R<<" "<<H<<" "<<X<<"\n";
		exit (0);
	}
}

void imprime()
{
	//cout<<X<<" "<<Y<<"\n";
	printf("%lf %lf\n",XT, Y );
}

void Eval(int abajo)
{
	XT = X + intervalo(1,999,90)/1000.0;
	E = R*R- (XT - H)*(XT - H);
	if (E<0)
		{XT = X - intervalo(1,999,90)/1000.0;
		E = R*R- (XT - H)*(XT - H);}
	revisa();
	if (abajo)
		Y = -sqrt(E) + K;
	else Y = sqrt(E) + K;

	if (fabs((Y - K)*(Y - K)+(XT - H)*(XT - H) - R*R) >1e-4)
	{
		cout<<"Error Raiz\n";
		printf("%lf\n",(Y - K)*(Y - K)+(XT - H)*(XT - H) - R*R );
		//cout<<(Y - K)*(Y - K)+(XT - H)*(XT - H) - R*R<<"\n";
		exit(0);
	}
}

int main()
{
	srand (time(NULL));
	r[0] = 200; r[1] = 20000;
	h[0] = 600; h[1] = 60000;
	char archivo[] = "C1.in";
	for (int caso = 0; caso < 2; ++caso)
	{
		for (char i = '0'; i <= '9'; ++i)
		{
			if (caso==0) archivo[0] = 'C';
			else if (caso==1) archivo[0] = 'M';			
			archivo[1] = i;

			freopen(archivo, "w", stdout);
			int c=150;
			cout<<c<<"\n";
			
			
			while(c--)
			{	
				//centro
				H = intervalo(1, 2*h[caso], 1);	H -= h[caso];
				K = intervalo(1, 2*h[caso], 2);	K -= h[caso];				

				//radio
				R = intervalo(100, r[caso], 3);

				//primer x, y
				X = intervalo(1, 2 * (R - 30), 4 );
				X = H - (R - 30) + X;
				Eval(0);				
				imprime();

				//segundo x, y
				Z = intervalo( 1, fabs( H + R - (X + 30) ), 5 );
				X = X + 30 + Z;
				Eval(0);
				imprime();

				//tercer x, y
				X = intervalo(1, 2 * (R - 30), 6 );
				X = H + (R - 30) - X;
				Eval(1);
				imprime();

				//segundo x, y
				Z = intervalo( 1, fabs( H - R - (X - 30) ), 7 );
				X = X - Z - 30;
				Eval(1);
				int es = rand()%2;
				if (not es)
					Y -= intervalo(r[caso]/4,r[caso]/2, 91);
				imprime();

				cout<<"\n";
			}
			
			fclose(stdout);

		}
	}
	
	return 0;
}