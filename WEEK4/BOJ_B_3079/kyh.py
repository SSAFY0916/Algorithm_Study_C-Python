# (골드 5) 3079 : 입국심사
# https://www.acmicpc.net/problem/3079
import sys

input = sys.stdin.readline
n, m = map(int, input().split())  # n: 심사대 수, m: 사람 수
times = [int(input()) for _ in range(n)]  # 심사대별 심사 시간

answer = 0
left, right = 1, max(times) * m
while left <= right:  # 이분 탐색
    mid = (left + right) // 2
    cnt = sum(mid // time for time in times)  # mid 시간 동안 심사할 수 있는 사람 수
    if cnt >= m:  # 모두 심사할 수 있으면 시간 줄이기
        right = mid - 1
        answer = mid
    else:  # 모두 심사할 수 없으면 시간 늘리기
        left = mid + 1

print(answer)
