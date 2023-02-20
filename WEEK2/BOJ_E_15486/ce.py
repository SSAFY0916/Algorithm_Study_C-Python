import sys

N = int(sys.stdin.readline())
data = [] * (N + 5)
dp = [0] * (N + 5)
for i in range(N):
  data.append(list(map(int, sys.stdin.readline().split())))

for i in range(N-1, -1, -1):
  if data[i][0] + i < N:
      dp[i] = max(dp[i + 1], data[i][1] + dp[i + data[i][0]])
  elif data[i][0] + i == N:
      dp[i] = max(data[i][1], dp[i + 1])
  else:
    dp[i] = dp[i + 1]


print(max(dp))
