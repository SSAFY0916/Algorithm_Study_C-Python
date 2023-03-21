import java.io.*;
import java.util.*;

public class Main_2240_자두나무 {

	/*
	 * 자두나무 
	 * 떨어지때까지 기다려야한다
	 * 매초 두개 나무 중 하나의 나무에서 열매가 떨어진다
	 * 떨어지는 순간 나무 아래 엤으면 열매 먹을 수 있다
	 * 자두 T초동안 떨어진다
	 * 최대 W번만 움직인다 
	 * 매초 자두가 떨어지는 나무 정보 
	 * 자두가 받을 수 있는 최대 자두의 개수
	 * 처음에 1번 자두나무에 있다
	 * */
	static int T, W, arr[], dp[][][],res;
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		st = new StringTokenizer(in.readLine());
		T = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		dp = new int[T+1][W+2][3];
		arr = new int[T+1];
		for (int i = 1; i <= T; i++) {
			arr[i] = Integer.parseInt(in.readLine());
		}

		
		for (int time = 1; time <= T; time++) {
			for(int moveCnt=1; moveCnt<=W+1; moveCnt++) {
				// 1번 나무에서 자두가 떨어질 경우
				if(arr[time]==1) {
					// 현재 1번에 서있을 경우
					dp[time][moveCnt][1] = Math.max(dp[time-1][moveCnt][1], dp[time-1][moveCnt-1][2]) + 1;
					// 현재 2번에 서있을 경우
					dp[time][moveCnt][2] = Math.max(dp[time-1][moveCnt][2], dp[time-1][moveCnt-1][1]);
				}else if(arr[time]==2) { // 2번 나무에서 자두가 떨어질 경우
					if(time==1 && moveCnt==1) continue;
					// 현재 1번에 서있을 경우
					dp[time][moveCnt][1] = Math.max(dp[time-1][moveCnt][1], dp[time-1][moveCnt-1][2]);
					// 현재 2번에 서있을 경우
					dp[time][moveCnt][2] = Math.max(dp[time-1][moveCnt][2], dp[time-1][moveCnt-1][1]) + 1;
				}
			}
		}
		
		for(int i=1; i<=W+1; i++) {
			res = Math.max(res, Math.max(dp[T][i][1], dp[T][i][2]));
		}
		
		System.out.println(res);
	}

}
