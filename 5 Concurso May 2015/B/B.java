import java.util.*;

class Bmain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		 
		while (tt-- > 0)
		{
			double mat[][] = new double[20][20], tot[] = new double[20];
			int arr[] = new int[505];
			int S, N;

			N = sc.nextInt();
			S = sc.nextInt();

			for(int j = 0; j < N; j++)
			{
				arr[j] = sc.nextInt();
				arr[j]--;
			}

			for(int j = 0; j < N-1; j++)
			{
				tot[arr[j]]++;
				mat[arr[j]][arr[j+1]]++;
			}

			for(int i = 0; i < S; i++)
			{
				for(int j = 0; j < S; j++)
				{
					if(tot[i] > 0)
						System.out.printf("%.2f ", mat[i][j] / tot[i]);
					else
						System.out.printf("%.2f ", mat[i][j]);
				}
				System.out.println();
			}
			System.out.println();
		}
	}
}