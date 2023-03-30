import java.util.*;
import java.io.*;

public class Main {

	static int N, K, graph[][], result;
	// 20경기 경희 민호 - 손동작번호 1~N
	static int var[][], win[], cnt[];
	static boolean used[], match[], isPossible;
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		graph = new int[N+1][N+1];
		var = new int[3][20];
		
		for(int i=1;i<=N;i++) { // 상성표 입력
			st = new StringTokenizer(in.readLine());
			for(int j=1;j<=N;j++) {
				graph[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		st = new StringTokenizer(in.readLine());
		for (int i=0;i<20;i++) {
			var[1][i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(in.readLine());
		for (int i=0;i<20;i++) {
			var[2][i] = Integer.parseInt(st.nextToken());
		}
		
		result = 0;
		win = new int[3];
		cnt = new int[3];
		used = new boolean[N+1];
		dfs(0, 1);

		System.out.println(result);
		
	}
	// 현재 지우가 낸 것
	private static void dfs(int p1, int p2) {
		
		if(result==1) {
			return;
		}
		if(win[0] >= K) {
			result = 1;
			return;
		}else if(win[1] >= K || win[2] >= K) {
			return;
		}else if(cnt[0] > N){
			return;
		}
		
		
		for(int num=1;num<=N;num++) {
			if(p1!=0 && p2!=0) {
				num = N;
			}else {
				if(used[num]) {
					continue;
				}
				used[num] = true;
				var[0][cnt[0]] = num;
			}
			
			// 참가자 확인, 다음 참가자 지정
			match = new boolean[3];
			match[p1] = true;
			match[p2] = true;
			int nextplayer = -1;
			for(int i=0;i<3;i++) {
				if(match[i] == false)
					nextplayer = i;
			}
			// 승자 확인
			int v1 = var[p1][cnt[p1]];
			int v2 = var[p2][cnt[p2]];
			int winner;
			if(graph[v1][v2] == 0) {
				winner = p2;
			}else if(graph[v1][v2] == 2) {
				winner = p1;
			}else {
				if(p1 < p2) {
					winner = p2;
				}else {
					winner = p1;
				}
			}
			win[winner]+=1;
			// 경기 수 증가
			cnt[p1]+=1;
			cnt[p2]+=1;
			
			dfs(winner, nextplayer);
			win[winner]-=1;
			cnt[p1]-=1;
			cnt[p2]-=1;
			used[num] = false;
		}
		
		
		
	}
	

}
