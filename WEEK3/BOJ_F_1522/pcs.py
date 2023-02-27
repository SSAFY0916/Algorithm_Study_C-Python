"""
[BOJ] 1522_문자열 교환
a b 로만 이루어진 문자열
A를 모두 연속으로 만들기 위해 필요한 교환 횟수를 최소로 하는 프로그램을 작성해라

문자열 원형이다
A가 연속이거나
B가 연속이거나

a개수 세서 a개수 만큼의 윈도우 생성
a윈도우로 스캔하면서 안에 B의 개수가 몇개인지 확인
B의 최소 개수로 갱신

원형 -> 처음부터 끝까지 확인, mod len(arr)
"""
arr = list(input())
window = []
ans = 1e9
for i in range(len(arr)):  # a 개수만큼 윈도우 생성
    if arr[i] == 'a':
        window.append('a')

for i in range(len(arr)):
    cnt_b = 0
    for j in range(len(window)):
        if arr[(i+j)%len(arr)] == 'b':
            cnt_b += 1
    ans = min(ans, cnt_b)

print(ans)

# a 윈도우로 스캔하면서 안에 B의 개수 확인, 최소 b개수로 갱신
# 범위는 끝까지, mod 연산,
# aaabaaaaba -> 배열
# aaaaaaaa   -> 윈도우 - 1번만 움직이면 된다.
