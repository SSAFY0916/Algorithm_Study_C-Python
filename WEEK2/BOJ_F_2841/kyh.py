# (실버 1) 2841 : 외계인의 기타 연주
# https://www.acmicpc.net/problem/2841
import sys

input = sys.stdin.readline

n, p = map(int, input().split())  # n : 멜로디에 포함되어 있는 음의 수, p : 한 줄에 있는 프렛의 수
line = [[] for _ in range(7)]  # 기타 줄
count = 0

for _ in range(n):
    l_num, p_num = map(int, input().split())
    l_num -= 1
    if not line[l_num]:  # 아무 프렛도 누르지 않은 경우
        line[l_num].append(p_num)  # 해당 줄의 프렛을 누름
        count += 1
    else:
        while line[l_num] and p_num < line[l_num][-1]:  # 주어진 줄의 더 높은 프렛을 누르고 있는 경우
            line[l_num].pop()  # 손가락을 하나씩 떼기
            count += 1
        if line[l_num] and line[l_num][-1] == p_num:  # 이미 누르고 있는 프렛인 경우
            continue
        line[l_num].append(p_num)  # 해당 줄의 프렛을 누름
        count += 1

print(count)  # 최소 손가락 움직임
