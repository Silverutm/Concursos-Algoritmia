/*

Entrada:

no_casos
bomba_x bomba_y
total_personas personas_afectar
persona0_x persona0_y
.
.
.
*

Ejemplo Entrada:

2
0 0
4 2
0 1
0 2
0 3
4 0
*
0 0
4 4
0 1
0 2
0 3
4 0
*

Ejemplo Salida:

12.57
50.27

*/

#include<stdio.h>
#include<math.h>

#define PI 3.14159265359

int p, k;
double bx, by;

void merge_sort(double v[], int n)
{
	if(n == 1)
		return;

	int cut = n >> 1, i, j, k;

	double v1[cut];
	double v2[n - cut];

	for(i = 0; i < cut; i++)
		v1[i] = v[i];

	for(j = 0; i < n; i++, j++)
		v2[j] = v[i];

	merge_sort(v1,cut);
	merge_sort(v2,n-cut);

	i = 0;
	j = 0;

	for(k = 0; k < n; k++)
	{
		if(i == cut)
		{
			for(;k < n; k++)
				v[k] = v2[j++];

			break;
		}

		if(j == n - cut)
		{
			for(;k < n; k++)
				v[k] = v1[i++];

			break;
		}

		if(v1[i] < v2[j])
			v[k] = v1[i++];
		else
			v[k] = v2[j++];
	}
}

double fun()
{
	double distances[p];	
	int i;
	double px,py;

	for(i = 0; i < p; ++i)
	{
		scanf("%lf %lf",&px,&py);
		distances[i] = sqrt( (bx-px)*(bx-px) + (by-py)*(by-py) );
	}

	merge_sort(distances,p);

	return distances[k-1]*distances[k-1]*PI;
}

int main()
{
	int n;
	char c[2];
/*
	freopen("abejas.in","r",stdin);
	freopen("abejas.out","w",stdout);*/

	scanf("%d",&n);

	while(n--)
	{ 
		scanf("%lf %lf",&bx,&by);
		scanf("%d %d",&p,&k);

		printf("%.2lf\n",fun());
		
		scanf("%s",c);
	}

}