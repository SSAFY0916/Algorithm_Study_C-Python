# (실버 4) 1388 : 바닥 장식
# https://www.acmicpc.net/problem/1388
import sys

input = sys.stdin.readline

n, m = map(int, input().split())  # n : 세로 크기, m : 가로 크기
data = [list(input().rstrip()) for _ in range(n)]  # 바닥 장식 데이터
count = 0  # 판자의 개수

for i in range(n):
    for j in range(m):
        if data[i][j] == '-':  # 가로 모양 판자일 때
            count += 1
            for z in range(j, m):  # 같은 행에 이어진 판자 있는지 확인
                if data[i][z] != '-':  # 가로 모양 판자가 아니라면 중단
                    break
                data[i][z] = None  # 방문했다는 표식으로 해당 지점 None으로 초기화해주기
        elif data[i][j] == '|':  # 세로 모양 판자일 때
            count += 1
            for z in range(i, n):  # 같은 열에 이어진 판자 있는지 확인
                if data[z][j] != '|':  # 세로 모양 판자가 아니라면 중단
                    break
                data[z][j] = None  # 방문했다는 표식으로 해당 지점 None으로 초기화해주기
print(count)
