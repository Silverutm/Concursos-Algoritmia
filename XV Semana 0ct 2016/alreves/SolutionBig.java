import java.io.*;
import java.util.*;
import java.math.*;

public class SolutionBig{

	public static boolean isPalindrome(String s) {
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) != s.charAt(s.length()-i-1)) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] acum = new int[1000010];

		acum[0] = 0;
		for(Integer i = 1; i <= 1000000; i++) {
			acum[i] = acum[i-1];
			if(isPalindrome(i.toString())) {
				acum[i]++;
			}
		}

		for (int k = 0; k < N; k++) {
			Integer a = sc.nextInt();
			Integer b = sc.nextInt();
			
			int cont = acum[b] - acum[a-1];

			System.out.println(cont);
		}
	}
}
