"""
[BOJ] 16947 서울 지하철 2호선
23.03.13 pcs
"""
"""
역과 역 사이 연결 51개
정점 51개
양방향 간선 51개
순환선 1개와 지선
한 역> 다시 출발한 역으로 돌아올 수 있는 노선 순환선
지선 - 순환선에 속하는 한역에서 시작하는 트리형태 노선
두역 사이 거리 - 지나야 하는 구간의 개수
역 A와 순환선 사이 거리 -> A와 순환선에 속하는 역 사이 거리 중 최솟값
2호선 같은 형태 노선도 - 각 역과 순환선 사이의 거리 구해라. 
 
"""
import sys
from collections import deque

sys.setrecursionlimit(10 ** 5)

n = int(input())
graph = [[] for _ in range(n+1)]
ans = [1e9 for _ in range(n+1)]
for i in range(n):
    fr, to = map(int, input().split())
    graph[fr].append(to)
    graph[to].append(fr)

def dfs(start, curr, visited, cnt):
    visited[curr] = True

    for node in graph[curr]:
        if start == node and cnt > 1:
            ans[start] = 0
            return
        if visited[node] is False:
            dfs(start, node, visited, cnt+1)


def find_len(start):
    q = deque()
    q.append((start, 1))
    visited = [False for _ in range(n+1)]
    visited[start] = True
    while q:
        curr, cnt = q.popleft()
        for node in graph[curr]:
            if visited[node] is False:
                if ans[node] == 0:
                    ans[start] = cnt
                    return
                q.append((node, cnt+1))
                visited[node] = True


for i in range(1, n+1):
    dfs(i, i, [False for _ in range(n+1)], 0)

for i in range(1, n+1):
    if ans[i] == 1e9:
        find_len(i)
for i in range(1, n+1):
    print(ans[i], end=" ")
