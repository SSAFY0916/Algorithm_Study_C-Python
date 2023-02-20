from collections import deque

N = int(input())
action = list(map(int, input().split()))
ans = deque()
action.reverse()

for i in range(N):
  if action[i] == 1:
    ans.appendleft(i + 1)
  if action[i] == 2:
    ans.insert(1, i + 1)
  if action[i] == 3:
    ans.append(i + 1)

for X in ans:
  print(X, end = " ")
