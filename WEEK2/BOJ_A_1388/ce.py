N, M = map(int, input().split())
board = []
ans = 0

for i in range(N):
  board.append(list(input()))

for i in range(N):
  wood = ''
  for j in range(M):
    if j == M - 1 and board[i][j] == '-':
      ans += 1
      break
    if board[i][j] == '-':
      if wood != '-':
        wood = '-'
    else:
      if wood == '-':
        ans += 1
        wood = board[i][j]
      else:
        wood = board[i][j]

for j in range(M):
  wood = ''
  for i in range(N):
    if i == N - 1 and board[i][j] == '|':
      ans += 1
      break
    if board[i][j] == '|':
      if wood != '|':
        wood = '|'
    else:
      if wood == '|':
        ans += 1
        wood = board[i][j]
      else:
        wood = board[i][j]
        
print(ans)
