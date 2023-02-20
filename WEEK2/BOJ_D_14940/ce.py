from collections import deque

n, m = map(int, input().split())
board = []
ans = [[-1] * m for i in range(n)]
q = deque()
dest_x = 0
dest_y = 0
visited = [[False] * m for _ in range(n)]

for i in range(n):
  board.append(list(map(int, input().split())))
  
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for i in range(n):
  for j in range(m):
    if board[i][j] == 2:
      dest_x = i
      dest_y = j

q.append([dest_x, dest_y])
visited[dest_x][dest_y] = True
ans[dest_x][dest_y] = 0

while q:
  cur = q.popleft()
  x = cur[0]
  y = cur[1]

  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if 0 <= nx < n and 0 <= ny < m:
      if visited[nx][ny] == False:
        if board[nx][ny] == 1 and ans[nx][ny] == -1:
          visited[nx][ny] = True
          ans[nx][ny] = ans[x][y] + 1
          q.append([nx, ny])
        elif board[nx][ny] == 0:
          visited[nx][ny] = True
          ans[nx][ny] = 0
          continue

ans[dest_x][dest_y] = 0

for i in range(n):
  for j in range(m):
    if board[i][j] == 0:
      ans[i][j] = 0
      
for i in range(n):
  for j in range(m):
    if j == m - 1:
      print(ans[i][j], end = "\n")
    else:
      print(ans[i][j], end = " ")
