# (실버 1) 3709 : 레이저빔은 어디로
# https://www.acmicpc.net/problem/3709
import sys

input = sys.stdin.readline
direction = {'up': (-1, 0), 'right': (0, 1), 'down': (1, 0), 'left': (0, -1)}
next_direction = {'up': 'right', 'right': 'down', 'down': 'left', 'left': 'up'}


def laser_box_game():
    n, r = map(int, input().split())  # n : 보드의 크기, r : 우향우 거울의 개수

    board = [[0] * (n + 1) for _ in range(n + 1)]  # 보드

    for _ in range(r):  # 우향우 장치 정보
        x, y = map(int, input().split())
        board[x][y] = 1

    laser_x, laser_y = map(int, input().split())  # 레이저 정보

    # 초기 레이저 방향 설정 
    if laser_x == 0:
        curr = 'down'
    elif laser_x == n + 1:
        curr = 'up'
    else:
        curr = 'right' if laser_y == 0 else 'left'

    while 1:
        laser_x += direction[curr][0]
        laser_y += direction[curr][1]
        if laser_x in (0, n + 1) or laser_y in (0, n + 1):  # 빔이 보드를 떠났을 때
            break  # 종료

        if board[laser_x][laser_y] != 0:  # 우향우 거울 있는 곳
            if board[laser_x][laser_y] == next_direction[curr]:  # 이전 방문시 우향우 했던 방향과 다음 우향우 할 방향이 같다면
                laser_x, laser_y = 0, 0  # 무한 반복이기 때문에 0, 0으로 초기화 후 종료
                break
            board[laser_x][laser_y] = curr = next_direction[curr]  # 다음 방향으로 보드와 curr 변수 초기화

    print(laser_x, laser_y)  # 빔이 보드를 떠나는 좌표


for _ in range(int(input())):
    laser_box_game()
