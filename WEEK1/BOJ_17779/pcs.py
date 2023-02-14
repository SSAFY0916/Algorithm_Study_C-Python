n = int(input())
graph = []
ground = [[0 for _ in range(n)] for _ in range(n)]
points = []
min_diff = 1e9

for i in range(n):
    graph.append(list(map(int, input().split())))


def select_point():
    for i in range(n):
        for j in range(n):
            x, y = i, j
            for k in range(1, y):
                d1 = k
                for l in range(1, n-1-y):
                    d2 = l
                    if d1+d2 > n-1-x:
                        continue
                    points.append([x,y,d1,d2])


def div_section(x,y,d1,d2):
    global ground

    # 경계선
    # (x, y), (x+1, y-1), ..., (x+d1, y-d1)
    for i in range(0, d1+1):
        ground[x+i][y-i] = 5
    # (x, y), (x+1, y+1), ..., (x+d2, y+d2)
    for i in range(0, d2+1):
        ground[x+i][y+i] = 5
    # (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
    for i in range(0, d2+1):
        ground[x+d1+i][y-d1+i] = 5
    # (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
    for i in range(0, d1+1):
        ground[x+d2+i][y+d2-i] = 5

    # 채우기
    for i in range(x+1, x+d1+d2):
        cnt = 0
        start = -1
        end = -1
        for j in range(y-d1, y-d1+d2+2):
            if ground[i][j] == 5:
                if cnt == 0:
                    cnt += 1
                else:
                    cnt -= 1
            if cnt > 0:
                ground[i][j] = 5

    # 1번 선거구
    for i in range(0,x+d1):
        for j in range(0,y+1):
            if ground[i][j] == 5:
                continue
            ground[i][j] = 1
    # 2번 선거구
    for i in range(0,x+d2+1):
        for j in range(y+1, n):
            if ground[i][j] == 5:
                continue
            ground[i][j] = 2
    # 3번 선거구
    for i in range(x+d1, n):
        for j in range(0,y-d1+d2):
            if ground[i][j] == 5:
                continue
            ground[i][j] = 3
    # 4번 선거구
    for i in range(x+d2+1, n):
        for j in range(y-d1+d2, n):
            if ground[i][j] == 5:
                continue
            ground[i][j] = 4


def count_people():
    global min_diff

    # 각 선거구의 합 1 ~ 5번
    people_sum = [0, 0, 0, 0, 0, 0]

    for i in range(n):
        for j in range(n):
            people_sum[ground[i][j]] += graph[i][j]
    people_sum.sort()

    min_diff = min(min_diff, people_sum[5]-people_sum[1])


select_point()  # 기준점 정하기 x,y d1, d2

for i in range(len(points)):
    ground = [[0 for _ in range(n)] for _ in range(n)]
    x,y,d1,d2 = points[i]
    div_section(x,y,d1,d2)
    count_people()

print(min_diff)