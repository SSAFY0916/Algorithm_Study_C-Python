# (골드 4) 16722 : 결! 합!
# https://www.acmicpc.net/problem/16722
import sys
from itertools import combinations

input = sys.stdin.readline

scb = [list(input().split()) for _ in range(9)]
success, fail = set(), set()
for a, b, c in combinations(range(1, 10), 3):
    cnt = 0
    for i in range(3):
        if len(set([scb[a - 1][i], scb[b - 1][i], scb[c - 1][i]])) in (1, 3):
            cnt += 1
    if cnt == 3:
        success.add((a, b, c))
    else:
        fail.add((a, b, c))

score, gFlag = 0, False
for _ in range(int(input())):
    command = list(input().split())
    if command[0] == 'H':
        a, b, c = sorted(map(int, command[1:]))
        if (a, b, c) in success:
            score += 1
            success.remove((a, b, c))
        else:
            fail.discard((a, b, c))
            score -= 1
    else:  # G
        if not gFlag and len(success) == 0:
            score += 3
            gFlag = True
        else:
            score -= 1

print(score)
