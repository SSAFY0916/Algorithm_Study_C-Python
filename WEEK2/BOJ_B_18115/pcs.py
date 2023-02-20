from collections import deque

n = int(input())
user_input = deque(map(int, input().split()))
org_card = deque()

for i in range(1, n+1):
    skill = user_input.pop()
    if skill == 1:
        org_card.appendleft(i)
    elif skill == 2:
        temp = org_card.popleft()
        org_card.appendleft(i)
        org_card.appendleft(temp)
    elif skill == 3:
        org_card.append(i)

for i in org_card:
    print(i, end=" ")

