import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Object;

class Bmain{


	public static ArrayList<Integer> primos = new ArrayList <Integer>();
	public static int []bs = new int[100*100+12];

	public static void criba(long lim)
	{

		bs[0] = bs[1] = 1;
		int i, j;

		for(i = 2; i*i <= lim; i++)
		{
			if(bs[i] == 0){
				primos.add(i);

				for(j = i*i; j<=lim; j+=i)
				{
					bs[j] = 1;
				}
			}
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a, b, A, B, T;
		long suma;

		T = sc.nextInt();

		criba(100*100+1);

		while(T-- > 0)
		{
			A = sc.nextInt();
			B = sc.nextInt();

			a = A;

			suma = 1;

			long p = 0;
			int j = 0, pf;

			pf = primos.get(j);

			while(pf*pf <= a)
			{
				p = 0;

				while(a % pf == 0)
				{
					a /= pf; p++;
				}

				suma *= (Math.pow(pf, p + 1) - 1) / (pf - 1);
				j++;
				pf = primos.get(j);

			}
			if(a != 1) suma *= (Math.pow(a, 2) - 1) / (a - 1);

			if((suma-A) == B)
				System.out.printf("Quiza y sin quiza\n");
			else
				System.out.printf("Llora desconsoladamente\n");
		}

	}
}