# (골드 4) 17404 : RGB거리 2
# https://www.acmicpc.net/problem/17404
import sys

input = sys.stdin.readline
N = int(input())  # 집의 수
color = [list(map(int, input().split())) for _ in range(N)]
result = int(1e9)

for i in range(3):  # 처음 시작을 빨 초 파 순으로 진행
    dp = [[0, 0, 0] for _ in range(N)]
    dp[0] = [int(1e9)] * 3
    dp[0][i] = color[0][i]
    for j in range(1, N):
        dp[j][0] = color[j][0] + min(dp[j - 1][1], dp[j - 1][2])  # 빨
        dp[j][1] = color[j][1] + min(dp[j - 1][0], dp[j - 1][2])  # 초
        dp[j][2] = color[j][2] + min(dp[j - 1][0], dp[j - 1][1])  # 파

    for j in range(3):
        if i != j:
            result = min(result, dp[-1][j])
print(result)
