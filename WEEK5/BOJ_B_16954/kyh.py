# (골드 3) 16954 : 움직이는 미로 탈출
# https://www.acmicpc.net/problem/16954
import sys
from collections import deque

input = sys.stdin.readline

wall_pos = set()  # 벽 위치
for i in range(8):
    temp = input().rstrip()
    for j in range(8):
        if temp[j] == '#':
            wall_pos.add((i, j))

queue = deque([(7, 0)])  # 캐릭터 시작 위치 넣기

result = 0
direction = [(i, j) for i in range(-1, 2) for j in range(-1, 2)]

while queue and wall_pos:
    temp = set()  # 이동할 수 있는 좌표 정보 임시로 저장
    for _ in range(len(queue)):
        r, c = queue.popleft()
        if (r, c) == (0, 7):  # 가장 오른쪽 윗 칸으로 도착할 수 있다면
            print(1)
            exit(0)

        for nr, nc in direction:
            rr, cc = r + nr, c + nc
            if not (0 <= rr <= 7 and 0 <= cc <= 7) or (rr, cc) in wall_pos:  # 불가능한 좌표 혹은 벽이 있는 위치라면
                continue
            temp.add((rr, cc))

    wall_update = set()  # 벽들을 아래로 내릴 위치 임시 저장
    for r, c in wall_pos:
        if r + 1 == 8:  # 가능한 범위를 넘어간다면
            continue
        wall_update.add((r + 1, c))
    wall_pos = wall_update  # 벽 정보 업데이트

    queue.extend(list(temp - wall_pos))  # 이동할 수 있는 좌표 중 벽들의 위치와 겹치지 않는 좌표들만 queue에 삽입

print(1 if not wall_pos and queue else 0)
