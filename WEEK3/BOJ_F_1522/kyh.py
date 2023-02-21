# (실버 1) 1522 : 문자열 교환
# https://www.acmicpc.net/problem/1522
import sys

input = sys.stdin.readline
data = input().rstrip()

count_a, count_b = data.count('a'), int(1e9)  # 문자열에서 각각 a와 b의 개수
length = len(data)  # 문자열 길이

for i in range(length):
    temp = 0
    for j in range(i, i + count_a):  # a 개수만큼 구간을 잘라서
        if data[j % length] == 'b':  # a가 아닌 b가 나오는 수 카운트
            temp += 1
    count_b = min(count_b, temp)  # 최소값으로 업데이트

print(count_b)
