import java.util.*;

class Fmain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();

		while (tt-- > 0)
		{
			int n = sc.nextInt(), m = sc.nextInt();
			double p[] = new double[n+1];

			double aux = 0.0;
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					int a = sc.nextInt();
					p[i] += a == 0 ? 0 : 1/(double)(m*a);
				}
			}

			double dp[][] = new double[n+1][n+1];
			
			dp[0][0] = 1.0;
			for (int i = 1; i <= n; ++i)
				for (int k = 0; k <= i; ++k)
					if (k == 0)
						dp[i][k] = (1.0-p[i])*dp[i-1][k];
					else
						dp[i][k] = p[i]*dp[i-1][k-1] + (1.0-p[i])*dp[i-1][k];

			double E = 0.0;
			for (int i = 1; i <= n; ++i)
				E += dp[n][i]*i;

			System.out.printf("%.2f\n", E);
		}
	}
}