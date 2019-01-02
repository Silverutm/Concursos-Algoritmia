import java.util.Scanner;

class E
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		
		while (T-- > 0)
		{
			int n = sc.nextInt(), s = sc.nextInt();

			int limNo = s % 2 == 0 ? s / 2 : s / 2 + 1;
			int limSi = s % 3 == 0 ? s / 3 : s / 3 + 1;

			if (n > limNo)
				System.out.println("No");
			else if (n <= limSi)
				System.out.println("Si");
			else
				System.out.println("Tal vez");
		}
	}
};