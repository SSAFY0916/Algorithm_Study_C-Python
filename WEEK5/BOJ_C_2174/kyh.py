# (골드 5) 2174 : 로봇 시뮬레이션
# https://www.acmicpc.net/problem/2174
import sys

input = sys.stdin.readline

direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
robot, pos = dict(), dict()

a, b = map(int, input().split())  # a : 가로, b : 세로
n, m = map(int, input().split())  # n : 로봇 수, m : 명령어 수

for i in range(n):
    x, y, d = input().split()
    x, y = int(x), int(y)
    robot[i + 1] = [y, x, 'NESW'.index(d)]
    pos[(y, x)] = i + 1

for _ in range(m):
    num, t, r = input().split()
    num, r = int(num), int(r)
    if t == 'L':
        robot[num][-1] = (robot[num][-1] + 4 - (r % 4)) % 4
    elif t == 'R':
        robot[num][-1] = (robot[num][-1] + r) % 4
    else:  # t=='F'
        curr_r, curr_c = robot[num][0], robot[num][1]
        del pos[(curr_r, curr_c)]
        for i in range(r):
            curr_r += direction[robot[num][2]][0]
            curr_c += direction[robot[num][2]][1]
            if not (1 <= curr_r <= b and 1 <= curr_c <= a):  # 벽에 부딪힐 때
                print('Robot {} crashes into the wall'.format(num))
                exit(0)
            if (curr_r, curr_c) in pos.keys():  # 다른 로봇이 있는 자리라면
                print('Robot {} crashes into robot {}'.format(num, pos[(curr_r, curr_c)]))
                exit(0)
        robot[num][0], robot[num][1] = curr_r, curr_c
        pos[(curr_r, curr_c)] = num

print('OK')
