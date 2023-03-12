from collections import deque
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
graph = []
for i in range(7):
    graph.append(list(map(int,input().split())))
num = int(input())
res = 1e9

def check_del_list(newGraph):
    del_list = []
    # 가로방향 확인
    visited = [[False for _ in range(7)] for _ in range(7)]
    for i in range(7):
        for j in range(7):
            if newGraph[i][j] > 0 and visited[i][j] is False:
                ny = j
                visited[i][j] = True
                temp = [(i,j)]
                for k in range(7):
                    ny += 1
                    if ny < 7 and newGraph[i][ny] > 0:
                        visited[i][ny] = True
                        temp.append((i,ny))
                    else:
                        break
                if len(temp) > 1:
                    for k in range(len(temp)):
                        x, y = temp[k]
                        if newGraph[x][y] > 0 and newGraph[x][y] == len(temp):
                            del_list.append((x,y))

    # 세로방향 확인
    visited = [[False for _ in range(7)] for _ in range(7)]
    for i in range(7):
        for j in range(7):
            if newGraph[j][i] > 0 and visited[j][i] is False:
                nx = j
                visited[j][i] = True
                temp = [(j,i)]
                for k in range(7):
                    nx += 1
                    if nx < 7 and newGraph[nx][i] > 0:
                        visited[nx][i] = True
                        temp.append((nx,i))
                    else:
                        break
                if len(temp) > 1:
                    for k in range(len(temp)):
                        x, y = temp[k]
                        if newGraph[x][y] > 0 and newGraph[x][y] == len(temp):
                            del_list.append((x,y))

    return del_list


def count_total(newGraph):
    global res
    cnt = 0
    for i in range(7):
        for j in range(7):
            if newGraph[i][j] > 0:
                cnt += 1
    res = min(res, cnt)


def poping(del_list, newGraph):

    for i in range(len(del_list)):
        x, y = del_list[i]
        newGraph[x][y] = 0


    for i in range(7):
        empty = -1
        for j in range(6, -1, -1):
            if newGraph[j][i] == 0:
                empty = j
            if newGraph[j][i] > 0 and j < empty:
                newGraph[j][i], newGraph[empty][i] = newGraph[empty][i], newGraph[j][i]
                empty = j

    count_total(newGraph)
    return newGraph


def drop(col):
    idx = 0
    for i in range(7):
        if graph[i][col] > 0:
            idx = i-1
            break
        if i == 6:
            idx = 6

    newGraph = []
    for i in range(7):
        newGraph.append(list(graph[i]))

    newGraph[idx][col] = num

    while True:
        del_list = check_del_list(newGraph)
        if len(del_list) == 0:
            break
        newGraph = poping(del_list, newGraph)


for i in range(7):
    drop(i)

print(res)
