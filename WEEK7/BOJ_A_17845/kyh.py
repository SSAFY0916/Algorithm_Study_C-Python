# (골드 5) 17845 : 수강 과목
# https://www.acmicpc.net/problem/17845
import sys

input = sys.stdin.readline
n, k = map(int, input().split())  # n : 최대 공부 시간, k : 과목 수
dp = [[0] * (n + 1) for _ in range(k + 1)]

for ii in range(k):
    i, t = map(int, input().split())  # i : 중요도, t : 필요한 공부 시간

    for j in range(1, n + 1):
        if j < t:
            dp[ii + 1][j] = dp[ii][j]
        else:
            dp[ii + 1][j] = max(dp[ii][j], dp[ii][j - t] + i)

print(dp[k][n])
