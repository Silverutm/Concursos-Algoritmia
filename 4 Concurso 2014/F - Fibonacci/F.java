import java.util.Scanner;

class F
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int[] dig = new int[]{1, 1, 2, 3, 5, 8, 1, 3, 4, 7}; 

		int T = sc.nextInt();
		while (T-- > 0)
		{
			int d = sc.nextInt();
			System.out.println(dig[(d-1)%10]);
		}
	}
};