# (골드 4) 1915 : 가장 큰 정사각형
# https://www.acmicpc.net/problem/1915
import sys

input = sys.stdin.readline
n, m = map(int, input().split())
data = [list(map(int, input().strip())) for _ in range(n)]

for i in range(1, n):
    for j in range(1, m):
        if data[i][j] == 1:
            data[i][j] += min(data[i - 1][j - 1], data[i - 1][j], data[i][j - 1])

print(max(map(max, data)) ** 2)
