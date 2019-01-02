import java.io.*;
import java.util.*;
import java.math.*;

public class SolutionLittle{

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

		for (int k = 0; k < N; k++) {
			Integer a = sc.nextInt();
			Integer b = sc.nextInt();
			int cont = 0;

			for(Integer i = a; i <= b; i++) {
				if(isPalindrome(i.toString())) {
					cont++;
				}
			}
			System.out.println(cont);
		}
	}
}
