# (골드 3) 8982 : 수족관 1
# https://www.acmicpc.net/problem/8982
import sys

input = sys.stdin.readline
n = int(input())
horizon_line_info = []
capacity = 0  # 수족관 물 전체 양

input()
for _ in range(n // 2 - 1):  # 수평 선분으로 데이터 입력받기
    col1, row1 = map(int, input().split())
    col2, row2 = map(int, input().split())
    horizon_line_info.append([row1, col1, col2 - col1, 0])
    capacity += row1 * (col2 - col1)
input()

k = int(input())
hole = []
for _ in range(k):
    a, b, c, d = map(int, input().split())
    hole.append((b, a))

hole.sort(key=lambda x: x[1])
idx = 0  # 홀 인덱스
line_len = len(horizon_line_info)

for i in range(line_len):
    row, col, size, fill = horizon_line_info[i]
    if (hole[idx][0], hole[idx][1]) != (row, col):
        continue
    hh = row
    for j in range(i, -1, -1):
        if horizon_line_info[j][3] >= hh:
            break
        if horizon_line_info[j][0] < hh:
            hh = horizon_line_info[j][0]
        horizon_line_info[j][3] = hh
    hh = row
    for j in range(i + 1, line_len):
        if horizon_line_info[j][3] >= hh:
            break
        if horizon_line_info[j][0] < hh:
            hh = horizon_line_info[j][0]
        horizon_line_info[j][3] = hh

    idx += 1
    if idx >= k:
        break

print(capacity - sum(map(lambda x: x[2] * x[3], horizon_line_info)))
