# (실버 3) 18115 : 카드 놓기
# https://www.acmicpc.net/problem/18115
import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
tech = list(map(int, input().split()))[::-1]  # 사용한 기술, 거꾸로 뒤집기

deq = deque()

for num, t in enumerate(tech, start=1):
    if t == 1:
        deq.appendleft(num)  # 제일 위에 카드 놓기
    elif t == 2:
        tmp = deq.popleft()  # 제일 위 카드 빼서
        deq.appendleft(num)  # 카드 넣고
        deq.appendleft(tmp)  # 다시 뺐던 카드 올려놓기
    else:
        deq.append(num)  # 제일 밑에 카드 넣기

print(' '.join(map(str, deq)))
