"""
[BOJ] 20056 마법사 상어와 파이어볼
23.03.06
박철순
"""
n, m, k = map(int, input().split())
graph = [[[] for _ in range(n)] for _ in range(n)]
new_graph = [[[] for _ in range(n)] for _ in range(n)]

# 0~7
# 상 상우 우 우하 하 하좌 좌 좌상
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]
res = 0

for i in range(m):
    # 파이어볼의 위치는 (ri, ci), 질량은 mi이고, 방향은 di, 속력은 si
    r, c, m, s, d = map(int, input().split())
    graph[r-1][c-1].append([m, s, d])


def move_fireball():
    global new_graph, graph
    new_graph = [[[] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if len(graph[i][j]) > 0:
                x, y = i, j
                for k in range(len(graph[i][j])):
                    m, s, d = graph[i][j][k]
                    nx = (x+dx[d]*s) % n
                    ny = (y+dy[d]*s) % n
                    new_graph[nx][ny].append([m, s, d])


def spread_fireball():
    global new_graph, graph

    for i in range(n):
        for j in range(n):
            if len(new_graph[i][j]) > 1:
                sum_m, sum_s, cnt_odd, cnt_even = 0, 0, 0, 0
                for m, s, d in new_graph[i][j]:
                    sum_m+=m
                    sum_s+=s
                    if d % 2:
                        cnt_odd += 1
                    else :
                        cnt_even += 1
                    # dir.append(d%2)
                sum_m = sum_m // 5
                sum_s = sum_s // len(new_graph[i][j])
                final_dir = []
                if cnt_odd == len(new_graph[i][j]) or cnt_even == len(new_graph[i][j]):
                    final_dir = [0,2,4,6]
                else:
                    final_dir = [1,3,5,7]
                new_graph[i][j] = []
                if sum_m > 0:
                    for d in final_dir:
                        new_graph[i][j].append([sum_m, sum_s, d])

    for i in range(n):
        for j in range(n):
            graph[i][j] = list(new_graph[i][j])


def check_sum():
    global res
    for i in range(n):
        for j in range(n):
            if len(graph[i][j]) > 0:
                for m,s,d in graph[i][j]:
                    res += m


for i in range(k):
    move_fireball()
    spread_fireball()

check_sum()
print(res)
