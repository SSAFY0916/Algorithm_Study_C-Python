# (골드 3) 16986 : 인싸들의 가위바위보
# https://www.acmicpc.net/problem/16986
import sys
from collections import deque
from itertools import permutations

input = sys.stdin.readline


def dfs(player):
    winner, opponent = 0, 1
    score = [0, 0, 0]
    while player[winner] and player[opponent]:
        winner_hand = player[winner].popleft()  # 전판 승자 손동작
        opponent_hand = player[opponent].popleft()  # 상대방 손동작

        if A[winner_hand][opponent_hand] == 1:  # 비긴 경우
            if winner < opponent:  # 전판 승자가 상대방보다 순서가 앞인 경우
                score[opponent] += 1
                winner, opponent = opponent, 3 - winner - opponent
            else:  # 전판 승자가 상대방보다 순서가 뒤인 경우
                score[winner] += 1
                opponent = 3 - winner - opponent
        elif A[winner_hand][opponent_hand] == 2:  # 전판 승자가 이긴 경우
            score[winner] += 1
            opponent = 3 - winner - opponent
        else:  # 전판 승자가 진 경우
            score[opponent] += 1
            winner, opponent = opponent, 3 - winner - opponent

        if score[winner] == K:  # K번 이긴 사람이 나온 경우
            if winner == 0:  # 그 사람이 지우인 경우
                return True
            return False

    return False


N, K = map(int, input().split())  # N: 인싸 가위바위보의 손동작 수, K: 승리해야 하는 횟수
A = [[0] * (N + 1)] + \
    [[0] + list(map(int, input().split())) for _ in range(N)]  # 상성에 대한 정보 - A[i][j]: i가 j를 이기면 2, 비기면 1, 지면 0

kyunghee = list(map(int, input().split()))
minho = list(map(int, input().split()))
jiwoo_hands = list(range(1, N + 1))

for jiwoo in permutations(jiwoo_hands, N):
    player = [deque(jiwoo), deque(kyunghee), deque(minho)]
    if dfs(player):
        print(1)
        exit()
print(0)
