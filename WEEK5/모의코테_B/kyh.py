# (골드 2) 1949 : 우수 마을
# https://www.acmicpc.net/problem/1949
import sys

sys.setrecursionlimit(10 ** 5)

input = sys.stdin.readline


def dfs(curr):
    visited[curr] = True
    for next in graph[curr]:
        if not visited[next]:
            dfs(next)
            dp[curr][0] += max(dp[next])  # 현재 마을이 우수 마을이 아닐 경우
            dp[curr][1] += dp[next][0]  # 현재 마을이 우수 마을일 경우
    dp[curr][1] += population[curr]


N = int(input())
population = [0] + list(map(int, input().split()))
graph = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

dp = [[0, 0] for _ in range(N + 1)]  # 리스트의 각 요소의 첫번째는 우수마을이 아닐 경우, 두번째는 우수 마을일 경우
visited = [False] * (N + 1)
dfs(1)

print(max(dp[1]))
