# (골드 5) 15486 : 퇴사 2
# https://www.acmicpc.net/problem/15486
import sys

input = sys.stdin.readline
n = int(input())  # 상담일자
data = [[0, 0]] + [list(map(int, input().split())) for _ in range(n)]  # 상담 일정표
dp = [0] * (n + 2)

max_ = -1
for i in range(1, n + 1):
    max_ = max(dp[i], max_)
    if i + data[i][0] - 1 <= n:  # 해당일로부터 소요일이 N일 안에 가능한지 확인
        dp[i + data[i][0]] = max(dp[i + data[i][0]], max_ + data[i][1])
print(max(dp))
