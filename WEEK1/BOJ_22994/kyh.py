# (실버 2) 22994 : 이미지 축소
# https://www.acmicpc.net/problem/22994
import sys
import math

input = sys.stdin.readline
print = sys.stdout.write
ni, mj = map(int, input().split())
data = [list(input().rstrip()) for _ in range(ni)]
i, j = ni, mj

for c in range(mj):  # i 값 찾기
    cnt, i_set = 1, set()
    for r in range(1, ni):
        if data[r - 1][c] == data[r][c]:  # 이전 문자와 현재 문자가 같다면
            cnt += 1
        else:  # 다르다면
            i_set.add(cnt)
            cnt = 1
    if not i_set:
        continue
    for ii in i_set:  # 최대공약수 구하기
        i = math.gcd(ii, i)
    if i == 1:
        break

for r in range(ni):  # j 값 찾기
    cnt, j_set = 1, set()
    for c in range(1, mj):
        if data[r][c - 1] == data[r][c]:  # 이전 문자와 현재 문자가 같다면
            cnt += 1
        else:  # 다르다면
            j_set.add(cnt)
            cnt = 1
    if not j_set:
        continue
    for jj in j_set:  # 최대공약수 구하기
        j = math.gcd(jj, j)
    if j == 1:
        break

# 결과 출력
print('{} {}\n'.format(ni // i, mj // j))  # n, m 출력
for r in range(0, ni, i):  # 원본 이미지 출력
    for c in range(0, mj, j):
        print(data[r][c])
    print('\n')
