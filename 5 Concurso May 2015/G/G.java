import java.util.*;

class Gmain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();

		while (tt-- > 0)
		{
			int a[] = new int[100005];

			int n = sc.nextInt();
			int m = sc.nextInt();

			boolean ok = true;
			for(int i = 0; i < n*m; i++)
			{
				int x = sc.nextInt();
				a[x]++;
				if (a[x] > n)
					ok = false;
			}

			System.out.printf("%s\n", ok ? "si" : "no");
		}
	}
}