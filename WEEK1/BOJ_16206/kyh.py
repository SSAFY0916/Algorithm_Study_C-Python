# (실버 1) 16206 : 롤케이크
# https://www.acmicpc.net/problem/16206
import sys

input = sys.stdin.readline

N, M = map(int, input().split())  # N : 롤케이크 수, M : 자를 수 있는 최대 횟수
roll_cake = sorted(map(int, input().split()), key=lambda x: (x % 10, x))  # 롤케이크 길이 정보

result = 0
for cake in roll_cake:
    q, r = divmod(cake, 10)  # 케이크 자르기(q : 길이가 10인 롤케이크 개수, r : 자르고 난 나머지)
    if r == 0:  # 딱 10크기로 롤케이크를 깔끔하게 자를 수 있는 경우
        M -= (q - 1)  # 자르는 횟수 = 잘라진 롤케이크 수 - 1
        result += q  # 10크기로 잘라진 롤케이크 수 더하기
    elif q != 0:  # 10크기의 롤케이크를 일부 자를 수 있고 나머지가 있는 경우
        M -= q  # 자르는 횟수 = 잘라진 롤케이크 수
        result += q  # 10크기로 잘라진 롤케이크 수 더하기
    else:  # 원래 롤케이크 크기가 10미만인 경우(q==0 and r!=0)
        continue

    if M == 0:  # 자른 횟수가 더이상 없을 때
        break
    if M < 0:  # 자른 횟수가 최대 횟수를 넘어갈 때
        result -= abs(M) + (r == 0)  # 결과에 더한 롤케이크 수 넘어간 횟수만큼 제거
        break

print(result)  # 결과 출력
