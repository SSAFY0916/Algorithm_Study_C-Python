import java.io.*;
import java.util.*;

public class Main {

	static int N, cnt[], dp[][], res;
	static ArrayList<ArrayList> graph;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(in.readLine());
		cnt = new int[N+1];
		dp = new int[N+1][2];
		graph = new ArrayList<>(); // index 가 있고, linkedList - index 접근 불가능
		for (int i = 0; i < N+1; i++) {
			graph.add(new ArrayList<Integer>());
		}
		
		st = new StringTokenizer(in.readLine());
		for (int i = 1; i <= N; i++) {
			cnt[i] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = 0; i < N-1; i++) {
			st = new StringTokenizer(in.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			graph.get(from).add(to);
			graph.get(to).add(from);
		}
		
		dfs(1, new boolean[N+1]);
		
		for (int i = 0; i < N+1; i++) {
			res = Math.max(res, dp[i][0]);
			res = Math.max(res, dp[i][1]);
		}
		
		System.out.println(res);
		
	}
	
	static private void dfs(int curr, boolean visited[]) {
		visited[curr] = true;
		dp[curr][1] = cnt[curr];
		
		if(graph.get(curr).size() == 0) {
			// 마지막 노드라면
			return;
		}
		
		
		for (int i=0; i<graph.get(curr).size(); i++) {
			int next = (int)graph.get(curr).get(i);
			if(!visited[next]) {
				dfs(next, visited);
				dp[curr][0] = dp[curr][0] + Math.max(dp[next][0], dp[next][1]);
				dp[curr][1] = dp[curr][1] + dp[next][0];
			}
		}
	}

	
}
