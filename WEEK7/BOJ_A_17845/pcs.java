import java.util.*;
import java.io.*;

public class Main {
	/*
	 * 어떤 과목을 들을지 고민중
	 * 학점 잘 받을 수 있으면서 중요한 과목을 듣고 싶다
	 * 모든 과목의 중요도와, 필요한 공부시간
	 * 공부시간의 한계를 초과하지 않으면서
	 * 과목의 중요도의 합이 최대가 되도록 몇 개만 선택하여 수강하자
	 * 공부시간의 한계를 초과하지 않으면서 중요도가 최대가 되도록 한다. 
	 * */
	static int priority[], time[];
	static int N, K, res,dp[][];
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		priority = new int[K+1];
		time = new int[K+1];
		// 0~k번째 과목까지 선택하면서 i인 시간일 때 들을 수 있는 최대 중요도
		dp = new int[K+1][N+1];
		for (int i = 1; i <= K; i++) {
			st = new StringTokenizer(in.readLine());
			priority[i] = Integer.parseInt(st.nextToken());//중요도
			time[i] = Integer.parseInt(st.nextToken());//공부시간 
		}
		
		// i번 과목부터 선택하면서
		for (int i=1;i<=K;i++) {
			for(int j=1;j<=N;j++) { // 해당 시간에 들을 수 있는 최대 중요도
				if(j >= time[i]) { // 현재 과목을 들을 수 있는 시간일 때 
					// ([(최대시간)-(현재과목 듣는데 걸리는 시간)]인 이전 과목까지의 중요도)+(현재 과목의 중요도)
					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-time[i]]+priority[i]);
				}else { // 현재 과목을 들을 수 없을 때 -> 이전 과목까지 들었을 때 최대값을 저장
					dp[i][j] = Math.max(dp[i-1][j], dp[i][j]);
				}
			}
		}
		
		System.out.println(dp[K][N]);	
	}

}
