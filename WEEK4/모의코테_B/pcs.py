
"""

연구소3

바이러스 유출
활성, 비활성 상태 있다
처음에 모든 바이러스 비활성
활성 바이러스 -<> 상하좌우 모든 빈칸 동시에 복제 1초
연구소 바이러스 m개를 활성상태로 변경하려고 한다.
NXN
빈칸 벽 바이러스 로 구분
활성 -> 비활성으로 가면 비활성 바이러스가 활성으로 바뀐다

0 빈칸 1 벽 2 바이러스

"""
from collections import deque
# 상하좌우
dx = [-1,1,0,0]
dy = [0,0,-1,1]
n, m = map(int, input().split())
graph = []
virus_pos = deque() # 바이러스 큐
res = 1e9
for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(n):
        if graph[i][j] == 2:
            virus_pos.append((i,j))
            graph[i][j] = -1
        elif graph[i][j] == 1:
            graph[i][j] = -99
    # 0 빈칸 1 벽 2 바이러스

# 바이러스 입력, 바이러스 퍼진다.
used = [False for _ in range(len(virus_pos))]


def bfs():
    global res
    q = deque()
    visited = [[-1 for _ in range(n)] for _ in range(n)]
    maxCnt = 0
    for i in range(len(used)):
        if used[i] is True:
            x, y = virus_pos[i]
            q.append(virus_pos[i])
            visited[x][y] = 0
    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx >= 0 and nx < n and ny >= 0 and ny < n:
                if visited[nx][ny] < 0:
                    if graph[nx][ny] == -1:
                        visited[nx][ny] = visited[x][y]
                        q.append((nx, ny))
                    elif graph[nx][ny] == 0:
                        visited[nx][ny] = visited[x][y] + 1
                        q.append((nx,ny))
                        maxCnt = max(maxCnt, visited[nx][ny])
        if maxCnt >= res: return
    for i in range(n):
        for j in range(n):
            if visited[i][j] == -1 and graph[i][j] == 0:
                return
    res = min(res, maxCnt)
    return


def dfs(curr, cnt):
    # 바이러스 위치 정하기
    if cnt == m:
        # bfs 시작
        bfs()
        return

    for i in range(curr, len(virus_pos)):
        if used[i] is False:
            used[i] = True
            dfs(curr+1, cnt+1)
            used[i] = False


dfs(0, 0)
if res == 1e9:
    print(-1)
else:
    print(res)
