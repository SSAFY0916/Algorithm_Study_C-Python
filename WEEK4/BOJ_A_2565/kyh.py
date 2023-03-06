# (골드 5) 2565 : 전깃줄
# https://www.acmicpc.net/problem/2565
import sys

input = sys.stdin.readline
n = int(input())
lines = [list(map(int, input().split())) for _ in range(n)]
lines.sort(key=lambda x: x[0])  # 전봇대 A 기준으로 오름차순 정렬

dp = [1] * n
for i in range(1, n):  # 반복문을 통해 가장 길게 증가하는 부분 수열의 길이를 구함
    for j in range(i):
        if lines[i][1] > lines[j][1]:
            dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))
