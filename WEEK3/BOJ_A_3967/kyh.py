# (골드 5) 3967 : 매직 스타
# https://www.acmicpc.net/problem/3967
import sys

input = sys.stdin.readline
print = sys.stdout.write
flag = False  # 정답을 찾았는지 체크하는 변수


def dfs(cnt, idx):
    global flag
    if cnt == fill_cnt:  # x의 빈 곳을 다 채웠을 때
        if data[0][4] + data[1][3] + data[2][2] + data[3][1] - 4 * 65 + 4 != 26: return
        if data[0][4] + data[1][5] + data[2][6] + data[3][7] - 4 * 65 + 4 != 26: return
        if data[1][1] + data[1][3] + data[1][5] + data[1][7] - 4 * 65 + 4 != 26: return
        if data[3][1] + data[3][3] + data[3][5] + data[3][7] - 4 * 65 + 4 != 26: return
        if data[1][1] + data[2][2] + data[3][3] + data[4][4] - 4 * 65 + 4 != 26: return
        if data[1][7] + data[2][6] + data[3][5] + data[4][4] - 4 * 65 + 4 != 26: return
        flag = True
        return

    for i in range(12):
        if visited[i]: continue  # 이미 채워진 알파벳이면 넘어감
        visited[i] = True  # 채워진 알파벳으로 체크
        data[pos[idx][0]][pos[idx][1]] = 65 + i  # 알파벳에 해당하는 아스키코드 값으로 채움
        dfs(cnt + 1, idx + 1)  # 다음 x로 넘어감
        if flag:  # 이미 정답을 찾았으면
            return
        data[pos[idx][0]][pos[idx][1]] = 'x'  # 다시 x로 바꿔줌
        visited[i] = False  # 다시 방문하지 않은 알파벳으로 체크


data, visited, pos = [], [0] * 12, []
fill_cnt = 0
for i in range(5):
    data.append(list(input().rstrip()))
    for j in range(9):
        if data[i][j] == 'x':  # x의 위치를 저장
            pos.append((i, j))
            fill_cnt += 1
        elif data[i][j] != '.':  # 이미 채워진 알파벳을 방문한 것으로 체크
            data[i][j] = ord(data[i][j])
            visited[data[i][j] - 65] = True

dfs(0, 0)

for i in range(5):
    for j in range(9):
        if data[i][j] != '.':  # 알파벳 자리라면 아스키코드를 문자로 바꿔서 출력
            print(chr(data[i][j]))
        else:  # 그대로 . 출력
            print('.')
    print('\n')
