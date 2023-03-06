# (골드 2) 1561 : 놀이 공원
# https://www.acmicpc.net/problem/1561
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
data = list(map(int, input().split()))
if n <= m:
    print(n)
    exit(0)

time = 0
left, right = 0, n * max(data)
while left <= right:
    mid = (left + right) // 2
    cnt = m + sum(mid // x for x in data)
    if cnt >= n:
        time = mid
        right = mid - 1
    else:
        left = mid + 1

complete = m + sum((time - 1) // x for x in data)

for i in range(m):
    if time % data[i] == 0:
        complete += 1
    if complete == n:
        print(i + 1)
        break
