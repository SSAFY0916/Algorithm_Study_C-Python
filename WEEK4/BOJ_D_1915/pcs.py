"""
[BOJ] 1915 가장 큰 정사각형
23.03.05 PCS
"""
n, m = map(int, input().split())
graph = []
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]  # DP를 편하게 하기 위해 0~n, 0~m
res = 0
# 1,1 ~ n,m까지 사용
for i in range(1, n+1):
    li = list(map(int, input()))
    for j in range(1, m+1):
        dp[i][j] = li[j-1]

for i in range(1, n+1):
    for j in range(1, m+1):
        if dp[i][j] > 0:
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            res = max(res, dp[i][j])


print(res * res)
# 정사각형 - 각 점에서 좌, 상, 좌상, 본인 -> 모두 1
