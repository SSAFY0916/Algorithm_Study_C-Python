"""
백준 매직스타 3967

"""

graph = [] # 9x5
visited = [False for i in range(0, 13)]
blank_idx = []
isAnswer = False
idx_list = [(0,4),
            (1,1), (1,3), (1,5), (1,7),
            (2,2), (2,6),
            (3,1), (3,3), (3,5), (3,7),
            (4,4)]
check_idx = [[1,3,6,8], [1,4,7,11], [2,3,4,5],
             [2,6,9,12], [5,7,10,12], [8,9,10,11]]
member = [0]
# 그래프 초기화, member 매직스타 구성 멤버 1번부터 초기화
for i in range(5):
    graph.append(list(input()))
    for j in range(9):
        if graph[i][j] != '.':
            if graph[i][j] == 'x':
                member.append(0)
            else:
                member.append(ord(graph[i][j])-64)
# visited - 사용한 숫자 체크, 비어있는 매직스타 멤버 idx 체크
for i in range(1, len(member)):
    if member[i] > 0:
        visited[member[i]] = True
    else:
        blank_idx.append(i)


def print_magic_star():  # 정답 매직스타 출력
    for i in range(12):
        x, y = idx_list[i]
        graph[x][y] = chr(member[i+1]+64)

    for i in range(5):
        for j in range(9):
            print(graph[i][j], end='')
        print()


def check_sum():  # 매직스타의 합을 확인한다.
    sums = []
    for i in range(6):
        mem_sum = 0
        for j in range(4):
            mem_sum += member[check_idx[i][j]]
        sums.append(mem_sum)
    for i in range(6):
        if sums[i] > 26 or sums[i] < 26:
            return False
    return True


def dfs(idx):
    global isAnswer
    if idx == len(blank_idx):  # 비어있는 매직스타 전부 채우면 합 확인
        if check_sum(): # 만약 정답이라면
            isAnswer = True
            print_magic_star()
        return

    if isAnswer is False:  # 아직 정답을 못찾았을 경우
        for i in range(1, 13):
            if visited[i]:
                continue
            member[blank_idx[idx]] = i
            visited[i] = True  # 방문해주고 다음 노드 체크
            dfs(idx+1)
            member[blank_idx[idx]] = 0
            visited[i] = False  # 방문 해제


dfs(0)
