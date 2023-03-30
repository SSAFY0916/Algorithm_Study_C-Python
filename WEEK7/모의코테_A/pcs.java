import java.io.*;
import java.util.*;

public class Main {

	/*
	 * 뱀과 사다리게임
	 * 주사위 원하는 수 나오게 하면 최소 몇번만에 도착점에 도착하는가
	 * 정육면체 1~6
	 * 10x10 총 100개 칸 
	 * 보드판 1~100
	 * i번칸 
	 * 100번칸 넘어가면 이동 불가능
	 * 도착칸 사다리 - 사다리타로 위고
	 * 뱀 - 뱀따라 내려간다
	 * 이동한 칸 번호 -원래 칸보다 크고
	 * 뱀 - 원래 칸보다 작아진다
	 * 1~ 100으로 도착
	 * 주사위 굴리는 최소 횟수
	 * 
	 * */
	static int N, M;
	static int ladder[], bam[];
	static int board[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		ladder = new int[101];
		bam = new int[101];
		board = new int[101];

		for (int i = 0; i < 101; i++) {
			board[i] = i;
		}
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			ladder[x] = y;
			board[x] = y;
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			bam[u] = v;	
			board[u] = v;
		}
		
		System.out.println(bfs(1));
	}
	
	private static int bfs(int start) {
		int cnt = 0;
		int check[] = new int[101];
		Deque<Integer> q = new ArrayDeque<Integer>();
		
		q.offer(start);
		while(!q.isEmpty()) {
			int x = q.poll();
			
			for(int i=1;i<=6;i++) {
				int nx = x+i;
				if(nx > 100) continue;
				if(check[board[nx]] == 0) {
					q.offer(board[nx]);
					check[board[nx]] = check[x] + 1;
				}
				if(board[nx] == 100) {
					return check[100];
				}
			}
		}
		return 0;
	}

}
