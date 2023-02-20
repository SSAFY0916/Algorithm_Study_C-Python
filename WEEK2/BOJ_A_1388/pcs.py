
"""
직사각형

- | 로 이루어짐
-- 인접 -> 같은 판자
|
|
-> 같은 판자

바닥 장식에 필요한 나무 판자 개수 출력

"""
from collections import deque

n, m = map(int, input().split())
graph = []
visited = [[False for _ in range(m)] for _ in range(n)]
cnt = 0
# 하 우 (판자의 방향 -> 같은 모양의 판자 -> 옆으로 or 밑으로)
dx = [1, 0]
dy = [0, 1]
for i in range(n):
    graph.append(list(input()))


def bfs(x, y, ch):  # ch -> 현재 판자 모양
    q = deque()
    q.append((x, y))

    while q:
        x, y = q.popleft()
        visited[x][y] = True
        if ch == '-':  # 판자가 '-' 모양 -> 옆으로 길이 확인
            dir = 1
        else:          # 판자가 '|' 모양 -> 아래로 길이 확인
            dir = 0
        nx = x+dx[dir]
        ny = y+dy[dir]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:  # 범위확인
            continue
        if visited[nx][ny] is True:  # 방문여부확인
            continue
        if graph[nx][ny] == ch:  # 같은 모양 판자 -> 하나의 판자
            q.append((nx, ny))


for i in range(n):
    for j in range(m):
        if visited[i][j] is False:  # 방문하지 않은 곳 BFS 진행
            bfs(i, j, graph[i][j])
            cnt += 1  # 판자 개수 = BFS 한 횟수

print(cnt)
