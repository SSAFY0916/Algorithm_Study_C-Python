# (실버 1) 1303 : 전쟁 - 전투
# https://www.acmicpc.net/problem/1303
import sys
from collections import deque

input = sys.stdin.readline


def bfs(start_r, start_c, ch):
    queue = deque([(start_r, start_c)])
    count = 0
    while queue:
        curr_r, curr_c = queue.popleft()
        if not visited[curr_r][curr_c]:
            count += 1
            visited[curr_r][curr_c] = True
            for dr, dc in ((0, 1), (0, -1), (-1, 0), (1, 0)):
                rr, cc = curr_r + dr, curr_c + dc
                if 0 <= rr < m and 0 <= cc < n and data[rr][cc] == ch:
                    queue.append((rr, cc))
    result[ch] += count * count  # 해당하는 팀에 count한 N명의 N^2 위력 더하기


n, m = map(int, input().split())  # n : 가로 크기, m : 세로 크기
data = [list(input().rstrip()) for _ in range(m)]
visited = [[False] * n for _ in range(m)]
result = {'W': 0, 'B': 0}

for i in range(m):
    for j in range(n):
        if not visited[i][j]:
            bfs(i, j, data[i][j])

print(result['W'], result['B'])  # 우리 병사의 위력의 합과 적국의 병사의 위력의 합
