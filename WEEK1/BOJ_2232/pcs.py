

"""
일직선상 n개 지뢰 같은 간격
각 지뢰 충격 강도  power
pi 초과하는 힘 가하면 pi만큼 힘으로 폭발
-> 좌우 지뢰에 힘을 발휘

1 2 5 4 3 3 6 6 2
첫번째 지뢰 터지면 2지뢰에 1만큼 힘 전달

5 지뢰 터지면
2, 4에 5 힘 전달
-> 2 터지고 양 옆에 2전달
-> 1 터지고 양 옆 전달, 전달 할 곳 없음 . 종료

-> 4 터지고 양 옆에 4 전달
-> 3 < 4 이므로 3 터지고 양옆 (아직 안터진 곳에 전달)
-> 6 >= 3 이므로 종료

최소 개수의 지뢰를 터트려서 모든 지뢰를 터뜨린다.
직접 터트려야 하는 지뢰를 구해라.

가장 센 지뢰 -> 터뜨린다.
남은 지뢰 중에 센 지뢰 터뜨린다.

"""
from collections import deque

def bomb(idx):
    global mine

    q = deque()
    q.append((idx-1, idx+1, mine[idx][1]))
    mine[idx][1] = 0
    while q:
        left, right, power = q.popleft()

        if left >= 0 and 0 < mine[left][1] < power:
            q.append((left-1, left+1, mine[left][1]))
            mine[left][1] = 0
        if right < n and 0 < mine[right][1] < power:
            q.append((right-1, right+1, mine[right][1]))
            mine[right][1] = 0


n = int(input())
mine = []
bomb_list = []
for i in range(n):
    mine.append([i, int(input())])
sort_mine = sorted(mine, key=lambda x:x[1], reverse=True)

# 가장 센 마인 순서로 터트리기
for i in range(n):
    if mine[sort_mine[i][0]][1] > 0:

        bomb(sort_mine[i][0])
        bomb_list.append(sort_mine[i][0]+1)

bomb_list.sort()
for i in range(len(bomb_list)):
    print(bomb_list[i])
