"""
[BOJ] 17404 RGB거리
23.02.26

집 N개 거리 선분
1번 ~ N번
집 - 빨 초 파
모든 집을 칠하는 비용 최솟값

1번 집 2번, N번과 달라야한다
N번 집 N-1, 1번과 달라야한다
1(2<= i <= n-1)번 집은 i-1, i+1번 집과 달라야 한다.
이웃한 집의 색은 달라야 한다.
"""

n = int(input())
cost = []
dp = [[1e9 for _ in range(3)] for _ in range(n)]  # 최대값으로 초기화
for i in range(n):
    cost.append(list(map(int, input().split())))  # 비용 입력 받음.

ans = 1e9

# dp[i][j] = 현재 j로 칠했을 때 최소 비용
# ==> min(dp[i-1][j-1], dp[i-1][j+1]) + cost[i][j]
for f in range(3):
    dp[0][f] = cost[0][f]  # 첫번째 집의 색깔
    for i in range(1, n):  # 2번집 ~ n-1 번집 칠하기
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]
    for i in range(3):
        if i == f:
            continue
        ans = min(ans, dp[n-1][i])
    dp[0][f] = 1e9  # 첫번째 집 색깔 고정

print(ans)