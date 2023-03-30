# (골드 5) 16928 : 뱀과 사다리 게임
# https://www.acmicpc.net/problem/16928
import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())  # N: 사다리의 개수, M: 뱀의 개수
board = [0] * 101  # 사다리와 뱀의 위치를 저장할 리스트
for _ in range(N + M):
    x, y = map(int, input().split())
    board[x] = y  # 사다리와 뱀의 위치를 저장

visited = [0] * 101  # 방문 여부를 저장할 리스트
queue = deque([1])  # 시작점
while queue:
    x = queue.popleft()
    if x == 100:  # 도착점에 도착하면 종료
        break
    for i in range(1, 7):  # 주사위를 굴림
        xx = x + i
        if not (1 <= xx <= 100) or visited[xx]:  # 범위를 벗어나거나 이미 방문했다면
            continue
        visited[xx] = visited[x] + 1  # 방문 표시
        if board[xx]:  # 사다리나 뱀이 있다면
            xx = board[xx]  # 이동
            if visited[xx]:
                continue
            visited[xx] = visited[x] + 1
        queue.append(xx)

print(visited[100])
