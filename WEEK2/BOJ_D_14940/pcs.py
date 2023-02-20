

from collections import deque

# 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
n, m = map(int, input().split())
graph = []
new_graph = [[-1 for _ in range(m)] for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]
q = deque()

for i in range(n):
    temp = list(map(int, input().split()))
    for j in range(m):
        if temp[j] == 2:  # 목표 지점
            q.append((i,j))
            visited[i][j] = True
            new_graph[i][j] = 0
        if temp[j] == 0:  # 벽, 갈 수 없는곳
            new_graph[i][j] = 0
    graph.append(temp)

# 목표지점부터 BFS 진행
while q:
    x, y = q.popleft()
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if visited[nx][ny] is True:
            continue
        if new_graph[nx][ny] == 0:
            continue
        q.append((nx, ny))
        visited[nx][ny] = True
        new_graph[nx][ny] = new_graph[x][y] + 1

for i in range(n):
    for j in range(m):
        print(new_graph[i][j], end=' ')
    print()

"""
실패 코드
* 메모리 초과, 시간 초과
** 불필요한 반복문 많이 사용
from collections import deque

# 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
n, m = map(int, input().split())
graph = []
visited = [[False for _ in range(m)] for _ in range(n)]
for i in range(n):
    graph.append(list(map(int, input().split())))


def bfs(x, y):  # 목표지점부터 BFS 진행
    q = deque()
    q.append((x,y))
    graph[x][y] = 0

    while q:
        x, y = q.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if visited[nx][ny] is True:
                continue
            if graph[nx][ny] == 0:
                continue
            q.append((nx, ny))
            graph[nx][ny] = graph[x][y] + 1
    # ************* 불필요한 반복문 1 ***********
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1 and visited[i][j] == False:
                print(-1, end=' ')  # 원래 갈 수 있는 땅 중에 도달할 수 없는 위치
            else:
                print(graph[i][j], end=' ')
        print()


isFind = False
# ************* 불필요한 반복문 2 ***********
for i in range(n):
    for j in range(m):
        if graph[i][j] == 2:
            bfs(i, j)
            isFind = True
            break
    if isFind is True:
        break
"""