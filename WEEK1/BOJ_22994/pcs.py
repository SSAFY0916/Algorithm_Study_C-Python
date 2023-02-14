
n, m = map(int, input().split())
graph = []
new_graph = []
x, y = 1, 1
min_y = 1e9
min_x = 1e9
y_list, x_list = [], []
for i in range(n):
    graph.append(list(input()))


def check_image():
    global x, y, y_list, x_list

    for j in range(m-1):
        if [graph[i][j] for i in range(n)] == [graph[i][j+1] for i in range(n)]:
            y += 1
        else:
            y_list.append(y)
            y = 1

    for i in range(n-1):
        if graph[i][:] == graph[i+1][:]:
            x += 1
        else:
            x_list.append(x)
            x = 1

    if len(x_list) == 0:
        x_list.append(1)
    if len(y_list) == 0:
        y_list.append(1)

    x_list.sort()
    y_list.sort()

def print_new_graph():
    global new_graph
    for i in range(0, n, x_list[0]):
        temp = []
        for j in range(0, m, y_list[0]):
            temp.append(graph[i][j])
        new_graph.append(temp)

    print(len(new_graph), len(new_graph[0]))
    for i in range(len(new_graph)):
        for j in range(len(new_graph[0])):
            print(new_graph[i][j], end="")
        print()

# 축소할 크기 구하기
check_image()
# 축소 배열 출력
print_new_graph()
