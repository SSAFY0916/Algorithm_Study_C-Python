"""
마법사 상어와 복제

4x4격자에 연습

맨위 1,1  4,4
격자 m마리 물고기
각물고기 칸하나, 방향 가지고 있다
8방향 상하좌우 대각선

상어 - 격자

둘 이상 물고기 같은 칸에 가능
상어 물고기 같은 칸 가능

마법
1. 물고기 복제 -> 5번에서 복제된 물고기 나타남
2. 물고기 1칸 이동, 상어 있는 칸, 물고기 냄새 칸, 격자범위밖 이동 불가능
막혔다면
이동할 수 있는 방향으로 45도 반시계 회전 //
이동할 수 있는 칸이 없으면 이동하지 않는다.
3. 상어 이동 3칸, 상어는 상하좌우 인접칸 이동 가능
격자 범위 벗어나면 그 방향으로는 이동불가
상어 이동하는 경로, 도착지 물고기 죽인다.
물고기 - 냄새 남긴다
합이 가장 큰 곳으로 이동, 합이 큰 곳이 여러개, 같은 값이 있다면, 사전순으로 이동
(사전순)
방향 -> 정수로 변환
상-1 좌-2 하-3 우-4
수를 이어 붙여 정수로 만든다
A < B이면 , 만든 숫자가 작은 값의 방향으로 간다.

4. 물고기 냄새 사라진다.

5. 1번에서 복제한 물고기 생성

"""


from collections import deque

# ←, ↖, ↑, ↗, →, ↘, ↓, ↙
# 좌 좌상 상 우상 우 우하 하 좌하
dx = [0, -1, -1, -1, 0, 1, 1, 1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

# 상어 이동 - 1~4 상 좌 하 우
ddx = [0, -1, 0, 1, 0]
ddy = [0, 0, -1, 0, 1]

m, s = map(int, input().split())
fish = []
# 각 칸 길이 - 물고기수, 값 - 방향
graph = [[[] for _ in range(4)] for _ in range(4)]
new_graph = []
temp_graph = []
smell = [[0 for _ in range(4)] for _ in range(4)]

for i in range(m):
    fx, fy, d = map(int, input().split())
    fish.append([fx-1, fy-1, d-1])
    graph[fx-1][fy-1].append(d-1)
sx, sy = map(int, input().split())
sx -= 1
sy -= 1


# def print_graph():
#     print("curr_graph")
#     for i in range(4):
#         print(graph[i])


def copy_fish():
    global graph, new_graph
    new_graph = [[[] for _ in range(4)] for _ in range(4)]
    for i in range(4):
        for j in range(4):
            if len(graph[i][j]) > 0:
                new_graph[i][j]=graph[i][j]


def move_fish_box(x, y):
    global temp_graph
    # 해당 칸 물고기
    isMove = [False for _ in range(len(graph[x][y]))]
    for i in range(len(graph[x][y])):
        dir = graph[x][y][i]
        # 모든 방향 보고 가능한 방향으로 이동,
        for j in range(8):
            nx = x+dx[dir]
            ny = y+dy[dir]
            # 범위 벗어나면 방향 전환(반시계로)
            if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:
                dir = ((dir-1)+8) % 8
                continue
            if nx == sx and ny == sy: # 상어위치일 때
                dir = ((dir-1)+8) % 8
                continue
            # 냄새일 때
            if smell[nx][ny] > 0:
                dir = ((dir-1)+8) % 8
                continue
            isMove[i] = True
            temp_graph[nx][ny].append(dir)
            break

    temp = graph[x][y]
    # print(temp)
    for i in range(len(graph[x][y])):
        if isMove[i] is False:
            temp_graph[x][y].append(temp[i])


def move_fish():
    global temp_graph, graph
    temp_graph = [[[] for _ in range(4)] for _ in range(4)]
    # print("물고기이동")
    for i in range(4):
        for j in range(4):
            if len(graph[i][j]) > 0:
                move_fish_box(i, j)
    # print("temp")
    # for i in range(4):
    #     print(temp_graph[i])
    graph = temp_graph


def move_position():
    global graph, sx, sy

    q = deque()
    visited = [[False for _ in range(4)] for _ in range(4)]
    q.append((sx,sy,0, 0))
    # print(sx,sy)
    visited[sx][sy] = True
    max_fish = 0
    mx, my = 0, 0
    max_move = [999 for _ in range(3)]
    curr_move = [-1 for _ in range(3)]
    while q:
        x,y,cnt,fish_cnt = q.popleft()
        visited[x][y] = True
        for i in range(1,5):
            nx = x+ddx[i]
            ny = y+ddy[i]
            if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:
                continue
            if visited[nx][ny] == True:
                continue
            if cnt < 3:
                curr_move[cnt] = i
                q.append((nx,ny,cnt+1,fish_cnt+len(graph[nx][ny])))
            else:
                if max_fish < fish_cnt:
                    if max_fish == fish_cnt: # 개수 같으면 사전순으로
                        for k in range(3):
                            if curr_move[k] < max_move[k]:
                                max_move = curr_move
                    else:
                        max_move = curr_move
                    max_fish = fish_cnt
    # print("move", max_move)

    for dir in max_move:
        sx += ddx[dir]
        sy += ddy[dir]
        smell[sx][sy] = 2
        graph[sx][sy] = []


def move_shark():
    move_position()


def remove_smell():
    for i in range(4):
        for j in range(4):
            if smell[i][j] > 0:
                smell[i][j] -= 1


def make_fish():
    # print("복사")
    global graph, new_graph
    for i in range(4):
        for j in range(4):
            if len(new_graph[i][j]) > 0:
                for k in range(len(new_graph[i][j])):
                    graph[i][j].append(new_graph[i][j][k])
    # print_graph()


# 구현 부 main
# print("fish", fish)
# print_graph()

def check_fish():
    totalCnt = 0
    for i in range(4):
        for j in range(4):
            totalCnt += len(graph[i][j])
    return totalCnt


for i in range(s):
    copy_fish()
    move_fish()
    move_shark()
    remove_smell()
    make_fish()

totalCnt = check_fish()
print(totalCnt)
