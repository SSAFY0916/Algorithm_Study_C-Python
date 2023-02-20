# (골드 1) [23290](https://www.acmicpc.net/problem/23290) : 마법사 상어와 복제

> ### 상어 이동을 for문으로 구현한 ver

```python
import sys
from collections import defaultdict

input = sys.stdin.readline

direction8 = [None, (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]  # ←, ↖, ↑, ↗, →, ↘, ↓, ↙
direction4 = [None, (-1, 0), (0, -1), (1, 0), (0, 1)]  # 상, 좌, 하, 우


def is_possible_pos(row, col):  # 유효한 위치인가
    return 1 <= row <= 4 and 1 <= col <= 4


def move_fishes():  # 1번 & 2번 : 원본 물고기를 moved_fish_pos에 옮기고 모든 물고기 한칸 이동
    global fish_pos, moved_fish_pos
    moved_fish_pos = defaultdict(list)  # 기존 물고기들을 이동시켰을 때 위치를 저장

    for r, c in fish_pos.keys():
        for d in fish_pos[(r, c)]:
            dd = d  # 기존 방향과의 비교를 위해 dd에 방향을 복사해서 사용
            for _ in range(8):
                rr, cc = r + direction8[dd][0], c + direction8[dd][1]
                if not is_possible_pos(rr, cc) or (rr, cc) == (shark_r, shark_c) or smell_pos[rr][cc] > 0:  # 불가능한 이동
                    dd = dd - 1 if dd != 1 else 8
                else:  # 가능한 이동
                    moved_fish_pos[(rr, cc)].append(dd)
                    break
            else:  # 모든 방향에 대해서 이동이 불가능한 경우
                moved_fish_pos[(r, c)].append(d)


def move_shark():  # 3번 : 상어 이동
    global moved_fish_pos, smell_pos
    global shark_r, shark_c
    temp_pos = [[], [], []]
    best_shark_pos = []
    for i in range(1, 5):
        if not is_possible_pos(shark_r + direction4[i][0], shark_c + direction4[i][1]):
            continue
        temp_pos[0] = (shark_r + direction4[i][0], shark_c + direction4[i][1])
        for j in range(1, 5):
            if not is_possible_pos(temp_pos[0][0] + direction4[j][0], temp_pos[0][1] + direction4[j][1]):
                continue
            temp_pos[1] = (temp_pos[0][0] + direction4[j][0], temp_pos[0][1] + direction4[j][1])
            for z in range(1, 5):
                if not is_possible_pos(temp_pos[1][0] + direction4[z][0], temp_pos[1][1] + direction4[z][1]):
                    continue
                temp_pos[2] = (temp_pos[1][0] + direction4[z][0], temp_pos[1][1] + direction4[z][1])
                count = 0
                for pos in set(temp_pos):
                    count += len(moved_fish_pos[pos])
                if not best_shark_pos or best_shark_pos[-1] < count:
                    best_shark_pos = [temp_pos[::], count]

    for r, c in best_shark_pos[0]:
        if moved_fish_pos[(r, c)]:  # 물고기 있다면
            smell_pos[r][c] = 3  # 냄새 남기고
            del moved_fish_pos[(r, c)]  # 물고기 제거

    for i in range(1, 5):
        for j in range(1, 5):
            if smell_pos[i][j] > 0:  # 냄새 있다면
                smell_pos[i][j] -= 1  # 냄새 제거

    shark_r, shark_c = best_shark_pos[0][-1]


def combine_fishes():  # 물고기를 이동시키고 상어를 움직였을 때 남은 물고기와 복제한 물고기 합치기
    global moved_fish_pos, fish_pos
    for key in moved_fish_pos.keys():
        fish_pos[key] += moved_fish_pos[key]
    moved_fish_pos = None


m, s = map(int, input().split())
fish_pos = defaultdict(list)  # 물고기 정보
moved_fish_pos = None  # 물고기 이동할 경우에 임시로 저장해둘 곳
smell_pos = [[0 for _ in range(5)] for _ in range(5)]  # 물고기 냄새 정보

for _ in range(m):
    r, c, d = map(int, input().split())
    fish_pos[(r, c)].append(d)

shark_r, shark_c = map(int, input().split())  # 상어 위치

for _ in range(s):
    move_fishes()
    move_shark()
    combine_fishes()

print(sum(map(len, fish_pos.values())))
```

<br><br>

> ### 상어 이동을 dfs를 활용해 구현한 ver

```python
# (골드 1) 23290 : 마법사 상어와 복제
# https://www.acmicpc.net/problem/23290
import sys
from collections import defaultdict

input = sys.stdin.readline

direction8 = [None, (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]  # ←, ↖, ↑, ↗, →, ↘, ↓, ↙
direction4 = [None, (-1, 0), (0, -1), (1, 0), (0, 1)]  # 상, 좌, 하, 우


def is_possible_pos(row, col):  # 유효한 위치인가
    return 1 <= row <= 4 and 1 <= col <= 4


def move_fishes():  # 1번 & 2번 : 원본 물고기를 moved_fish_pos에 옮기고 모든 물고기 한칸 이동
    global moved_fish_pos
    moved_fish_pos = defaultdict(list)  # 기존 물고기들을 이동시켰을 때 위치를 저장

    for r, c in fish_pos.keys():
        for d in fish_pos[(r, c)]:
            dd = d  # 기존 방향과의 비교를 위해 dd에 방향을 복사해서 사용
            for _ in range(8):
                rr, cc = r + direction8[dd][0], c + direction8[dd][1]
                if not is_possible_pos(rr, cc) or (rr, cc) == (shark_r, shark_c) or smell_pos[rr][cc] > 0:  # 불가능한 이동
                    dd = dd - 1 if dd != 1 else 8
                else:  # 가능한 이동
                    moved_fish_pos[(rr, cc)].append(dd)
                    break
            else:  # 모든 방향에 대해서 이동이 불가능한 경우
                moved_fish_pos[(r, c)].append(d)


def find_best_shark_pos_with_dfs(rr, cc, depth, count, visit):
    global best_shark_path, shark_r, shark_c, max_count
    if depth == 3:
        if max_count < count:
            max_count = count
            best_shark_path = visit[:]
            shark_r, shark_c = rr, cc
        return

    for i in range(1, 5):
        nx, ny = rr + direction4[i][0], cc + direction4[i][1]
        if not is_possible_pos(nx, ny):
            continue
        if (nx, ny) not in visit:
            visit.append((nx, ny))
            find_best_shark_pos_with_dfs(nx, ny, depth + 1, count + len(moved_fish_pos[(nx, ny)]), visit)
            visit.pop()
        else:
            find_best_shark_pos_with_dfs(nx, ny, depth + 1, count, visit)


def move_shark():  # 3번 : 상어 이동
    global moved_fish_pos, smell_pos, best_shark_path

    for rr, cc in best_shark_path:
        if moved_fish_pos[(rr, cc)]:  # 물고기 있다면
            smell_pos[rr][cc] = 3  # 냄새 남기고
            del moved_fish_pos[(rr, cc)]  # 물고기 제거

    for i in range(1, 5):
        for j in range(1, 5):
            if smell_pos[i][j]:  # 냄새 있다면
                smell_pos[i][j] -= 1  # 냄새 제거


def combine_fishes():  # 물고기를 이동시키고 상어를 움직였을 때 남은 물고기와 복제한 물고기 합치기
    global moved_fish_pos, fish_pos
    for key in moved_fish_pos.keys():
        fish_pos[key] += moved_fish_pos[key]
    moved_fish_pos = None


m, s = map(int, input().split())
fish_pos = defaultdict(list)  # 물고기 정보
moved_fish_pos = None  # 물고기 이동할 경우에 임시로 저장해둘 곳
smell_pos = [[0 for _ in range(5)] for _ in range(5)]  # 물고기 냄새 정보

for _ in range(m):
    r, c, d = map(int, input().split())
    fish_pos[(r, c)].append(d)

shark_r, shark_c = map(int, input().split())  # 상어 위치

for _ in range(s):
    move_fishes()
    best_shark_path = []
    max_count = -1
    find_best_shark_pos_with_dfs(shark_r, shark_c, 0, 0, [])
    move_shark()
    combine_fishes()

print(sum(map(len, fish_pos.values())))
```
