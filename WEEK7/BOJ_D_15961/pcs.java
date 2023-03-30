import java.util.*;
import java.io.*;

public class Main {
	/*
	 * 회전초밥 초밥 접시 - 손님 골라먹는다
	 * 종류 - 번호
	 * 같은 종류 둘 이상 있을 수 있다. 
	 * 행사를 한다
	 * 
	 * - 임의 한위치 부터 K개 접시를 연속해서 먹을 경우 - 할인 정액가격으로 제공
	 * - 각 고객 초밥 종류 쿠폰, 1번 행사 참여 -> 쿠폰에 적인 초밥하나 무료 제공 / 초밥이 벨트위에 없으면 새로 만들어서 준다.
	 * 가능한 다양한 초밥먹는다. 
	 * 벨트 상태, 메뉴 초밥 가짓수, 연속해서 먹는 접시 갯수, 쿠폰 번호 - 손님이 먹을 수 있는 최대 가짓수
	 * 
	 * 슬라이딩 윈도우?
	 * 최대 길이 3000, 쿠폰의 초밥을 제외한 최대 가짓수는 몇개인가?
	 * */	
	static int N, d, k, c, count[], arr[], result, cnt;
	//static HashSet<Integer> set;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		count=new int[3001];
		arr = new int[N];
		for(int i=0;i<N;i++) {
			int tmp = Integer.parseInt(in.readLine());
			arr[i] = tmp;//i번째 초밥
		}
		
		// 초기 window k사이즈만큼 생성
		for(int i=0; i<k; i++) {
			if(count[arr[i]] == 0) cnt++;
			count[arr[i]]++;
		}
		
		for(int i=1; i<N; i++) {//슬라이딩 윈도우
			count[arr[i-1]]--;
			if(count[arr[i-1]] == 0) // 남은 초밥이 없다면
				cnt--;

			if(count[arr[(k-1+i)%N]] <= 0) // 새로운 초밥이라면
				cnt++;
				
			count[arr[(k-1+i)%N]]++;// %N - 회전초밥
			
			// 최대값 갱신
			if(count[c] == 0) // 쿠폰 초밥 안먹었다면
				result = Math.max(result, cnt+1);
			else // 쿠폰 초밥 먹었다면
				result = Math.max(result, cnt);
		}

		System.out.println(result);
	}
}
