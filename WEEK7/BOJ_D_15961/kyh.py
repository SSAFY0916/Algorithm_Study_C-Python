# (골드 4) 15961 : 회전 초밥
# https://www.acmicpc.net/problem/15961
import sys

input = sys.stdin.readline

N, d, k, c = map(int, input().split())  # N : 접시 수, d : 초밥 가짓수, k : 연속해서 먹는 접시 수, c : 쿠폰 번호
sushi = [int(input()) for _ in range(N)]

cnt = [0] * (d + 1)  # 초밥 종류별 개수
cnt[c], type_cnt = 1, 1

for i in range(k):
    if cnt[sushi[i]] == 0:  # 새로운 종류의 초밥
        type_cnt += 1
    cnt[sushi[i]] += 1

result = type_cnt

for end in range(k, N + k - 1):  # end : 끝 접시 번호
    cnt[sushi[end - k]] -= 1  # 이전 첫 접시 제거
    if not cnt[sushi[end - k]]:  # 이전 첫 접시가 마지막 종류였다면
        type_cnt -= 1  # 종류 수 감소

    cnt[sushi[end % N]] += 1  # 마지막 접시 추가

    if cnt[sushi[end % N]] == 1:  # 마지막 접시가 새로운 종류인 경우
        type_cnt += 1  # 종류 수 증가
    result = max(result, type_cnt)

print(result)
