import java.util.*;
import java.io.*;

public class Main {
	
	static int n, m;
	static int[][] road;
	static boolean visited[];
	static int parent[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		while(true) {
			st = new StringTokenizer(in.readLine());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			if(m+n == 0) return;
			
			road = new int [n][3];
			int orgCost = 0;
			int minCost = 0;
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());
				int cost = Integer.parseInt(st.nextToken());
				road[i] = new int[] {from, to, cost};
				orgCost += cost;
			}
			// 각 노드의 부모를 저장.
			parent = new int[m]; 
			//makeset
			for(int i=0;i<m;i++)
				parent[i] = i;
			
			// 크루스칼, 비용으로 정렬
			Arrays.sort(road, (o1, o2) -> {
				return o1[2] - o2[2]; // 3번째(비용) 기준으로 오름차순 정렬
			});
			
			for (int i = 0; i < n; i++) {
				int from = road[i][0];
				int to = road[i][1];
				int cost = road[i][2];
				// 비용이 가장 적은 간선을 선택하면서 서로 다른 집합의 있는 것이면 해당 간선 선택 union
				if(find(from) != find(to)) {
					//부모가 다를 때만 선택 - 더이상 선택할 간선이 없을 때까지
					union(from, to);
					minCost += cost;
				}
			}
			System.out.println(orgCost - minCost);

		}
	}
	
	private static void union(int a, int b) {
		a = find(a);
		b = find(b);
		if(a>b) {
			parent[a] = b;
		}else {
			parent[b] = a;
		}
	}
	
	private static int find(int x) {
		if(parent[x] == x)
			return x;
		else
			return find(parent[x]);
	}
}
