"""
1번줄 6번줄
각 줄 P개 프랫
프렛 1~P번

멜로디 - 음의 연속
4번줄 8번 프렛,
프렛 어러개 - 가장 높은 프렛 (숫자가 높은 프렛 연주)

5번 -> 7번 7번 손가락 누른다 -> 2번 -> 5번 7번 떼고 2번 누른다

프렛 누르거나 떼는 것 - 손가락 움직인 횟수
멜로디 -> 손가락 가장 적게 움직이는 횟수 구해라
"""
from collections import deque

n, p = map(int, input().split())
isUsed = [False for _ in range(6)]  # 기타 줄 사용 여부
pret_list = [[] for _ in range(6)]  # 사용중인 프렛 번호
cnt = 0
for i in range(n):
    r, pret = map(int, input().split())
    r -= 1
    if isUsed[r] is False:  # 새로운 기타 줄
        isUsed[r] = True
        pret_list[r].append(pret)
        cnt += 1
    else:  # 사용 중인 기타 줄
        while True:
            if len(pret_list[r]) > 0:
                if pret_list[r][len(pret_list[r])-1] < pret:  # 새로운 음이 높은 음이라면
                    pret_list[r].append(pret)
                    cnt += 1
                    break
                elif pret_list[r][len(pret_list[r])-1] > pret:
                    pret_list[r].pop()
                    cnt += 1
                else:  # 만약에 같은 pret이 들어오면 아무일 X
                    break
            else:  # 더 이상 손뗄 음이 없다면
                pret_list[r].append(pret)
                cnt += 1
                break

print(cnt)
