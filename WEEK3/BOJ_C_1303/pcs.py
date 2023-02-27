"""
[BOJ] 1303_전쟁-전투
23.02.26

전쟁 시작
내병사 - 흰색
적병사 - 파란색

N명 뭉치면 N^2파워
지금 상황에서 누가 이길 것인가
상하좌우 인접

각 그룹의 힘의 합

"""

from collections import deque

# 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
n, m = map(int, input().split())
pow_w, pow_b = 0, 0
graph = []
visited = [[False for _ in range(n)] for _ in range(m)]
for i in range(m):
    graph.append(list(input()))


def bfs(x, y, ch):
    global pow_b, pow_w
    q = deque()
    q.append((x,y))
    visited[x][y] = True
    pow = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx >= 0 and nx < m and ny >= 0 and ny < n:
                if visited[nx][ny] is False and graph[nx][ny] == ch:  # 아직 방문하지 않은 곳
                    q.append((nx, ny))
                    visited[nx][ny] = True
                    pow += 1

    if ch == 'W':
        pow_w += pow**2
    elif ch == 'B':
        pow_b += pow**2


for i in range(m):
    for j in range(n):
        if visited[i][j] is False:
            bfs(i, j, graph[i][j])

print(pow_w, pow_b)