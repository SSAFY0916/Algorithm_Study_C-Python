# (골드 3) 16637 : 괄호 추가하기
# https://www.acmicpc.net/problem/16637
N = int(input())
data = list(map(lambda x: int(x) if x.isdigit() else x, input()))
result = -int(1e9)


def calculate(num1, num2, s):  # 연산자 s에 따라 계산처리
    if s == '+':
        return num1 + num2
    elif s == '-':
        return num1 - num2
    elif s == '*':
        return num1 * num2


def dfs(idx, prev):
    global result
    if idx >= N:  # 연산이 끝났을 때
        result = max(result, prev)  # 최댓값 갱신
        return
    if idx + 3 < N:  # 괄호 사용 가능
        # 현재 연산자 위치 다음에 나오는 연산자에 대해 괄호로 묶어 계산
        dfs(idx + 4, calculate(prev, calculate(data[idx + 1], data[idx + 3], data[idx + 2]), data[idx]))
    dfs(idx + 2, calculate(prev, data[idx + 1], data[idx]))  # 괄호로 묶지 않고 계산


if N == 1:  # 주어진 수가 하나일 때
    result = data[0]
else:
    dfs(1, data[0])

print(result)
