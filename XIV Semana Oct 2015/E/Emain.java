import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Object;


class Emain{

	public static Boolean clockW(int []p, int []q, int []r)
	{
		int s = (q[0]-p[0])*(r[1]-p[1]) - (q[1]-p[1])*(r[0]-p[0]);
		if(s >= 0)
			return true;
		else
			return false;
	}
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		int C;

		C = sc.nextInt();
		int n, a, b;
		int [][] P = new int[100 + 10][2];
		int [] punto = new int[2];


		while(C-- > 0)
		{
			n = sc.nextInt();

			for(int i = 0; i<n; i++)
			{
				a = sc.nextInt();
				b = sc.nextInt();

				P[i][0] = a; P[i][1] = b;
			}

			a = sc.nextInt();
			b = sc.nextInt();

			punto[0] = a; punto[1] = b;

			Boolean lado = clockW(P[0], P[1], punto);
			Boolean si = true;

			for(int j = 1; j < n; j++)
			{
				Boolean l = clockW(P[j], P[(j+1)%n], punto);

				if(l != lado)
				{
					si = false;
					break;
				}
			}

			if(si == true)
				System.out.printf("si\n");
			else
				System.out.printf("no\n");
		}

	}
}