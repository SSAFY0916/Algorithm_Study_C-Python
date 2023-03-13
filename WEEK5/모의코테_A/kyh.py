# (골드 5) 25331 : Drop 7
# https://www.acmicpc.net/problem/25331
import sys

input = sys.stdin.readline


def bomb_row():
    global dd
    bomb_pos = set()
    for r in range(7):
        size = 7 - dd[r].count(0)
        if size == 0:
            continue
        for c in range(7):
            if dd[r][c] == size:
                bomb_pos.add((r, c))
    return bomb_pos


def bomb_col():
    global dd
    bomb_pos = set()
    for c in range(7):
        r = 0
        while r < 7:
            if dd[r][c] == 0:
                r += 1
                continue
            size = 1
            while r + size < 7 and dd[r + size][c] != 0:
                size += 1

            for k in range(r, r + size):
                if dd[k][c] == size:
                    bomb_pos.add((k, c))
            r += size
    return bomb_pos


def move(bomb_pos):
    global dd
    for r, c in bomb_pos:
        dd[r][c] = 0

    for r in range(7):
        temp = list(filter(lambda x: x != 0, dd[r]))
        dd[r] = [0] * (7 - len(temp)) + temp


data = [list(tt) for tt in zip(*[list(map(int, input().split())) for _ in range(7)])]
num = int(input())
result = 49

for p in range(7):
    dd = [data[i][::] for i in range(7)]
    for i in range(6, -1, -1):
        if dd[p][i] == 0:
            dd[p][i] = num
            break

    while 1:
        bomb = set()
        bomb.update(bomb_row())
        bomb.update(bomb_col())
        if not bomb:
            break
        move(bomb)
    result = min(result, 49 - sum(map(lambda x: x.count(0), dd)))

print(result)
