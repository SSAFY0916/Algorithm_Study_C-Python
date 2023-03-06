# (골드 3) 17142 : 연구소 3
# https://www.acmicpc.net/problem/17142
import sys
from collections import deque
from itertools import combinations

input = sys.stdin.readline


def bfs(active_virus):
    time = 0
    queue, visited = deque(), [[-1] * n for _ in range(n)]
    for r, c in active_virus:
        queue.append((r, c))
        visited[r][c] = 0

    while queue:
        r, c = queue.popleft()
        for dr, dc in (1, 0), (-1, 0), (0, 1), (0, -1):
            nr, nc = r + dr, c + dc
            if not (0 <= nr < n and 0 <= nc < n) or visited[nr][nc] != -1 or data[nr][nc] == 1:
                continue

            visited[nr][nc] = visited[r][c] + 1
            if data[nr][nc] == 0:
                time = max(time, visited[nr][nc])
            queue.append((nr, nc))

    if sum(map(lambda x: x.count(-1), visited)) != wall:
        return int(1e9)

    return time


n, m = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(n)]  # 0: 빈칸, 1: 벽, 2: 바이러스
wall = 0
virus = []  # 바이러스 위치
for i in range(n):
    for j in range(n):
        if data[i][j] == 1:
            wall += 1
        if data[i][j] == 2:
            virus.append((i, j))

result = min(list(map(bfs, combinations(virus, m))))

print(result if result != int(1e9) else -1)
