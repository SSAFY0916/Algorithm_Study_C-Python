# (골드 3) 2206 : 벽 부수고 이동하기
# https://www.acmicpc.net/problem/2206
import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())

direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]
data = [list(map(int, list(input().strip()))) for _ in range(n)]


def bfs():
    queue = deque([(0, 0, 1)])
    visit = [[[0] * 2 for _ in range(m)] for _ in range(n)]
    visit[0][0][1] = 1
    while queue:
        r, c, dist = queue.popleft()
        if (r, c) == (n - 1, m - 1):
            return visit[r][c][dist]
        for i in range(4):
            rr, cc = r + direction[i][0], c + direction[i][1]
            if not (0 <= rr < n and 0 <= cc < m): continue

            if data[rr][cc] == 1 and dist == 1:
                visit[rr][cc][0] = visit[r][c][1] + 1
                queue.append((rr, cc, 0))
            elif data[rr][cc] == 0 and visit[rr][cc][dist] == 0:
                visit[rr][cc][dist] = visit[r][c][dist] + 1
                queue.append((rr, cc, dist))
    return -1


print(bfs())
