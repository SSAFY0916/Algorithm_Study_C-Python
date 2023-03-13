# (골드 3) 16947 : 서울 지하철 2호선
# https://www.acmicpc.net/problem/16947
import sys
from collections import deque

sys.setrecursionlimit(10 ** 5)

input = sys.stdin.readline
print = sys.stdout.write


def dfs(start, curr, depth):
    global dist, visited

    visited[curr] = True
    for next in graph[curr]:
        if not visited[next]:  # 방문하지 않은 역이라면
            dfs(start, next, depth + 1)
        elif next == start and depth > 1:  # 다시 처음 역을 돌아오는 경우
            dist[start] = 0
            return


def calc_distance():
    global dist
    queue = deque()
    for i in range(n):
        if dist[i] == 0:  # 순환선에 속하는 역이라면
            queue.append(i)

    while queue:
        curr = queue.popleft()
        for next in graph[curr]:  # 현재역에서 다음역으로 갈 수 있는 경로 중
            if dist[next] == -1:  # 아직 방문하지 않은 역이라면
                dist[next] = dist[curr] + 1
                queue.append(next)

    print(' '.join(map(str, dist)))


n = int(input())
graph = [[] for _ in range(n)]
dist = [-1] * n

for _ in range(n):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

for i in range(n):
    visited = [False] * n
    dfs(i, i, 0)

calc_distance()
