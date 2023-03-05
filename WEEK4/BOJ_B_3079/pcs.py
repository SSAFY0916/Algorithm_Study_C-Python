"""
[BOJ] 3079 입국심사
23.03.05 pcs
심사를 마치는데 걸리는 시간을 이분탐색
정답을 X라고 가정
시간 X동안 (1명당 시간 Y가 걸리는 심사관은) 최대 X/Y명을 처리할 수 있다.
이분 탐색, 매개 탐색
"""

def main():
    # 친구 m 심사대 n
    n, m = map(int, input().split())
    time = []
    cnt = [0 for _ in range(n)]
    for i in range(n):
        time.append(int(input()))

    # left = 0
    left = min(time)
    # right = int(1e9)  <- 실패
    right = max(time) * m  # 초기화 중요**
    res = right  # 초기화 중요**
    while left<=right:
        mid = (left+right)//2
        sum= 0
        for i in range(n):
            sum += mid // time[i] # mid 시간동안 i번 심사대에서 심사를 받을 수 있는 인원

        if sum >= m: # 더 많이 할 수 있다면
            right = mid - 1
            res = min(mid, res)
        else:  # 부족하다면
            left = mid+1
    print(res)

main()