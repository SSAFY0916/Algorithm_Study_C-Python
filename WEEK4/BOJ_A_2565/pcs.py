"""
[BOJ] 2565 전깃줄
23.03.05 pcs
"""
n = int(input())
line = []
for i in range(1, n+1):
    a, b = map(int,input().split())
    line.append([a,b])
line.sort(key=lambda x:x[0])
dp = [1 for _ in range(n)]
for i in range(n):
    for j in range(i+1):
        if line[i][1] > line[j][1]:
            dp[i] = max(dp[i], dp[j]+1)
print(n - max(dp))

# A로 정렬 후에 B가 연속으로 증가하는 최대 개수를 측정한다.
# 가장 긴 증가하는 부분 수열
# dp[끝나는 인덱스] = 끝나는 인덱스일 때 최장 부분 수열