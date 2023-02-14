# (골드 3) 17779 : 게리맨더링 2
# https://www.acmicpc.net/problem/17779
import sys

input = sys.stdin.readline


def simulation(x, y, d1, d2):
    section = [0] * 5  # 구역별 인구 수
    temp_c = y
    for r in range(x + d1):  # 1구역 인구 합 구하기
        if r >= x:
            temp_c -= 1
        section[0] += sum(data[r][0:temp_c + 1])

    temp_c = y - d1 - 1
    for r in range(x + d1, n):  # 3구역 인구 합 구하기
        section[2] += sum(data[r][0:temp_c + 1])
        if r < x + d1 + d2:
            temp_c += 1

    temp_c = y + 1
    for r in range(x + d2 + 1):  # 2구역 인구 합 구하기
        if r > x:
            temp_c += 1
        section[1] += sum(data[r][temp_c:])

    temp_c = y + d2
    for r in range(x + d2 + 1, n):  # 4구역 인구 합 구하기
        section[3] += sum(data[r][temp_c:])
        if r <= x + d1 + d2:
            temp_c -= 1

    section[4] = total - sum(section)  # 5구역 인구 합 구하기

    return max(section) - min(section)


n = int(input())  # 재현시의 크기
data = [list(map(int, input().split())) for _ in range(n)]  # 구역별 인구수
total = sum(map(sum, data))  # 인구수 총합
result = int(1e9)  # 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값

for x in range(n - 2):  # 기준점 (x, y) : 0 <= x < N-2, 1 <= y < N-1
    for y in range(1, n - 1):
        for d1 in range(1, y + 1):  # 경계 d1, d2 : 1 <= d1 <= y, 1 <= d2 <= N-y
            for d2 in range(1, n - y + 1):
                if x + d1 + d2 < n and y - d1 >= 0 and y + d2 < n:
                    result = min(result, simulation(x, y, d1, d2))
                else:
                    break
print(result)
