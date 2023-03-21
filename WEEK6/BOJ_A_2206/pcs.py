"""
[BOJ] 2206 벽 부수고 이동하기
23.03.20 pcs
"""

"""
nxm 0 이동가능 1벽 
1,1  n,m 이동 
최단 경로로 이ㅏ동한다

맵에서 가장 적은 개수칸을 지나는 경로이다
벽 최대 1개 부수기 가능
상하좌우 이동 가능
"""
from collections import deque
n,m = map(int, input().split())
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
graph = []
for i in range(n):
    graph.append(list(map(int, input())))
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]


def bfs():
    global visited
    q = deque()

    q.append((0,0,0))
    visited[0][0][0] = 1
    while q:
        x,y,isBroken = q.popleft()
        if x == n-1 and y == m-1:
            return visited[x][y][isBroken]
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if graph[nx][ny] == 0 and visited[nx][ny][isBroken] == 0:
                q.append((nx,ny,isBroken))
                visited[nx][ny][isBroken] = visited[x][y][isBroken] + 1
            if graph[nx][ny] == 1 and isBroken == 0:
                q.append((nx,ny,isBroken+1))
                visited[nx][ny][isBroken+1] = visited[x][y][isBroken] + 1
    return -1


print(bfs())
