# (실버 2) 2232 : 지뢰
# https://www.acmicpc.net/problem/2232
import sys

input = sys.stdin.readline
n = int(input())  # 지뢰 수
p_arr = [0] + [int(input()) for _ in range(n)] + [0]  # 지뢰들의 충격 강도

result = []  # 결과
for i in range(1, n + 1):  # 터트릴 지뢰 번호 찾기
    if p_arr[i - 1] <= p_arr[i] and p_arr[i + 1] <= p_arr[i]:
        result.append(i)

print('\n'.join(map(str, result)))  # 직접 터트리는 지뢰 번호 출력
