import java.util.*;

class Amain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		int a[] = new int[1005], b[] = new int[1005];
		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();

		for(int i = 0; i < n; i++)
			b[i] = sc.nextInt();

		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += a[i] == b[i] ? 1 : 0;

		System.out.println(ans);
	}
}