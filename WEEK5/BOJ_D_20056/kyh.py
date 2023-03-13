# (골드 4) 20056 : 마법사 상어와 파이어볼
# https://www.acmicpc.net/problem/20056
import sys
from collections import defaultdict

input = sys.stdin.readline


def move():
    global fireball
    update = defaultdict(list)
    while fireball:
        r, c, m, s, d = fireball.pop()
        r = (r + direction[d][0] * s) % N
        c = (c + direction[d][1] * s) % N
        update[(r, c)].append([m, s, d])

    for (r, c) in update.keys():
        if len(update[(r, c)]) == 1:  # 파이어볼이 하나인 경우
            fireball.append([r, c] + update[(r, c)][0])
            continue
        # 파이어볼을 합쳐야 하는 경우
        m_sum, s_sum, even, length = 0, 0, 0, len(update[(r, c)])
        for m, s, d in update[(r, c)]:
            m_sum += m
            s_sum += s
            if d % 2 == 0:  # 속도가 짝수라면
                even += 1

        if not m_sum // 5:  # 질량이 0이라면
            continue

        dd = [0, 2, 4, 6] if even in (0, length) else [1, 3, 5, 7]  # 나눠질 파이어볼 방향
        for d in dd:
            fireball.append([r, c, m_sum // 5, s_sum // length, d])


direction = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
fireball = list()

N, M, K = map(int, input().split())

for _ in range(M):
    r, c, m, s, d = map(int, input().split())  # r : 행, c : 열, m : 질량, s : 속력, d : 방향
    fireball.append([r, c, m, s, d])

for _ in range(K):
    move()

print(sum(map(lambda x: x[2], fireball)))  # 질량의 합
