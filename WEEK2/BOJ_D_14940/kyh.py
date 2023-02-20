# (실버 1) 14940 : 쉬운 최단거리
# https://www.acmicpc.net/problem/14940
import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())  # n : 세로 크기, m : 가로 크기
data = [list(map(int, input().split())) for _ in range(n)]  # 지도 데이터
start_r, start_c = -1, -1  # 시작 위치

for i in range(n):
    for j in range(m):
        if data[i][j] == 2:  # -> 목표 지점
            start_r, start_c = i, j  # 시작 위치로 설정
            data[i][j] = 0
            break

visited = [[False] * m for _ in range(n)]  # 방문여부 저장
queue = deque([(start_r, start_c, 0)])

while queue:  # bfs 수행
    row, col, val = queue.popleft()
    if not visited[row][col]:  # 방문하지 않은 지점이라면
        visited[row][col] = True  # 방문 처리
        for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):  # 상하좌우
            temp_r, temp_c = row + dr, col + dc
            if 0 <= temp_r < n and 0 <= temp_c < m and data[temp_r][temp_c] == 1 and not visited[temp_r][temp_c]:
                # 방문하지 않았고 갈 수 있는 땅이라면
                data[temp_r][temp_c] = val + 1
                queue.append((temp_r, temp_c, val + 1))

for i in range(n):
    for j in range(m):
        if data[i][j] == 1 and not visited[i][j]:  # 갈 수 있는 땅이지만 도달할 수 없는 위치라면
            data[i][j] = -1
        print(data[i][j], end=' ')
    print()
