
T = int(input())
n = 0
turn_rule = []
top, bottom, front, back, left, right = [],[],[],[],[],[]


def rotate_90(graph):
    for i in range(3):
        for j in range(3):
            graph[j][2-i] = graph[i][j]
    return graph


def rotate_270(graph):
    for i in range(3):
        for j in range(3):
            graph[2-j][i] = graph[i][j]
    return graph


def rotation_up(direction):
    global top, bottom, front, back, left, right
    print("up")
    if direction == '+': # 위-시계
        # 큐브 사이드 이동
        front[0], left[0], back[0], right[0] = right[0], front[0], left[0], back[0]
        # 큐브 면 이동
        top = rotate_90(top)
    elif direction == '-': # 위-반시계
        front[0], left[0], back[0], right[0] = left[0], back[0], right[0], front[0]
        top = rotate_270(top)
    print("f", right[for i in range(3)][0])
    print("", right[:])


def rotation_down(direction):
    global top, bottom, front, back, left, right
    print("down")
    if direction == '-': # 위-시계 = 아래 반시계
        # 큐브 사이드 이동
        front[0], left[0], back[0], right[0] = right[0], front[0], left[0], back[0]
        # 큐브 면 이동
        bottom = rotate_270(bottom)
    elif direction == '+': # 위 반시계 = 아래-시계
        front[0], left[0], back[0], right[0] = left[0], back[0], right[0], front[0]
        bottom = rotate_90(bottom)
    print("f", right[:][0])

# def rotation_front(direction):
#     global top, bottom, front, back, left, right
#     print("front")
#     if direction == '+': # 앞-시계 = 뒤 반시계
#         top[2] =
#         top[2], right[i for i in range(3)][0], bottom[0], left[[r[2] for r in left] =
#         bottom = rotate_270(bottom)
#     elif direction == '-': # 위 반시계 = 아래-시계
#         front[0], left[0], back[0], right[0] = left[0], back[0], right[0], front[0]
#         bottom = rotate_90(bottom)



def turn_cude():
    global turn_rule
    for i in range(n):
        pos, direction = turn_rule[i][0], turn_rule[i][1]
        print(pos, direction)
        if pos == 'U':
            rotation_up(direction)
        elif pos == 'D': # 위 아래
            rotation_down(direction)
        # elif pos == 'F' or pos == 'B': # 앞 뒤
        #     rotation_front_back(pos, direction)
        # elif pos == 'L' or pos == 'R': # 왼쪽 오른쪽
        #     rotation_left_right(pos, direction)


for tc in range(1, T+1):
    top = [['w' for _ in range(3)] for _ in range(3)]
    bottom = [['y' for _ in range(3)] for _ in range(3)]
    front = [['r' for _ in range(3)] for _ in range(3)]
    back = [['o' for _ in range(3)] for _ in range(3)]
    left = [['g' for _ in range(3)] for _ in range(3)]
    right = [['b' for _ in range(3)] for _ in range(3)]

    # 초기 큐브
    print(top)
    print(bottom)
    print(front)
    print(back)
    print(left)
    print(right)
    print()

    n = int(input())

    turn_rule = list(input().split())
    print("turn_rule", turn_rule)

    turn_cude()