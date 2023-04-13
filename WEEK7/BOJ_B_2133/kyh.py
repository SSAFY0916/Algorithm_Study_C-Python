# (골드 4) 2133 : 타일 채우기
# https://www.acmicpc.net/problem/2133
n = int(input())
if n % 2 == 1:
    print(0)
    exit(0)

dp = [0] * (n + 1)
dp[2] = 3

for i in range(4, n + 1, 2):
    dp[i] += dp[i - 2] * 3
    for j in range(i - 4, 0, -2):
        dp[i] += dp[j] * 2
    dp[i] += 2

print(dp[n])
