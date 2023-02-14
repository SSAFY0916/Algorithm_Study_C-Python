
"""
nxn

임의 칸 - 우향우 거울 장치 설치
마지막으로 레이저 한개 설치

레이저는 판의 끝에만 설치 가능
행의 맨 아래, 맨위
열의 오른쪽 끝, 왼쪽 끝에 설치 가능
레이저 -> 행 또는 열 -> 반대쪽을

우향우 어굴 임의 칸 설치 -> 레이저를 배치 -> 시작

레이저 켰을때 빔이 우향우 거울 통과하면 오른쪽으로 90도 쩍어 다시 나아간다.
마지막으로 어느 좌표를 향해 비춰지는가


"""
from collections import deque
# 상 우 하 좌
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def start_beam(x, y):
    global n

    dir = -1
    # 행 방향으로 레이저 쏘기
    if x >= n+1:
        dir = 0 # 상
    elif x <= 0:
        dir = 2 # 하
    elif y >= n+1:
        dir = 3 # 좌
    elif y <= 0:
        dir = 1 # 우

    q = deque()
    q.append((x,y, dir))

    while q:
        x, y, dir = q.popleft()
        nx = x+dx[dir]
        ny = y+dy[dir]

        if nx <= 0 or nx >= n+1 or ny <= 0 or ny >= n+1:
            print(nx, ny)
            break
        if graph[nx][ny] > 0:
            # 방향전환 오른쪽 90도
            visited_mirror[nx][ny] = 1
            dir = (dir+1) % 4

        q.append((nx, ny, dir))


T = int(input())
start_x, start_y = 0, 0
n, r = 0, 0
visited_mirror = []

for test_case in range(1, T+1):
    n, r = map(int, input().split())
    # graph 크기 -> 0~n+1, 거울 위치 - 1~n
    graph = [[0 for _ in range(n+2)] for _ in range(n+2)]
    visited_mirror = [[0 for _ in range(n+2)] for _ in range(n+2)]
    for i in range(r):
        x, y = map(int, input().split())
        # 우향우 거울 x,y 위치에 설치 1~n-2, 1~n-2
        graph[x][y] = 1

    start_x, start_y = map(int, input().split())

    # 빔이 보드를 떠나는 좌표 x, y를 구해라.
    start_beam(start_x, start_y)