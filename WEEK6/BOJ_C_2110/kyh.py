# (골드 4) 2110 : 공유기 설치
# https://www.acmicpc.net/problem/2110
import sys

input = sys.stdin.readline
n, c = map(int, input().split())
house = [int(input()) for _ in range(n)]

house.sort()

start, end = 1, house[-1] - house[0]
result = 0

while start <= end:
    mid = (start + end) // 2
    cnt = 1
    temp = house[0]
    for i in range(1, n):
        if house[i] >= temp + mid:  # 공유기 설치 가능
            cnt += 1
            temp = house[i]
    if cnt >= c:  # 공유기 설치 가능한 수가 c보다 크거나 같으면
        start = mid + 1
        result = mid
    else:  # c개의 공유기 설치가 불가능하면
        end = mid - 1
print(result)
