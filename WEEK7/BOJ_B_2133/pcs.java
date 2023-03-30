import java.util.*;
import java.io.*;


public class Main {
	static int arr[], cnt, N;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[31];
		arr[2] = 3;
		
		// 점화식을 구해야 하는 문제, 규칙을 찾아야 하는 문제
		// 홀 수 일 때는 조건을 만족할 수 없음 3*3 -> 홀수, 블록은 무조건 짝수 개수
		/*
		 * f(2) = 3
		 * f(4) = 3*3 + 2
		 * f(6) = f(4)*3 + 2 + f(2)*2
		 * f(8) = f(6)*3 + 2 + f(2)*2 + f(4)*2
		 * ...
		 * f(n) = f(n-2) + 2 + (f(2)*2 + f(4)*2 + ... + f(n-4)*2)
		 * */
		
		for(int i=4; i<=30; i+=2) {
			arr[i] = arr[i-2] * 3 + 2;
			for(int j=2;j<=i-4;j+=2) {
				arr[i] += arr[j] * 2;
			}
		}
		System.out.println(arr[N]);		
	}
}
