"""
[BOJ] 16637_괄호 추가하기
23.02.26

괄호 넣지 않고 계산, 괄호 넣고 계산

"""

n = int(input())
arr = list(input())
res = -1e9


def calc(a, b, op):  # 계산하는 함수
    if op == '+':
        return a + b
    elif op == '*':
        return a * b
    elif op == '-':
        return a - b


def dfs(idx, before):
    global res
    if idx >= n:
        res = max(res, before)  # result = 누적 계산값의 최대
        return

    temp = 0
    op = '+' if (idx < 2) else arr[idx-1]   # operation = 처음은 '+', 이후에는 idx-1번째 원소의 연산자
                                            #  (idx-1) (idx) (idx+1) (idx+2) (idx-1)
                                            # 3   +     8       *       7      -      9 * 2
    # 괄호 X
    temp = calc(before, ord(arr[idx])-ord('0'), op)  # 이전 계산값 (연산자) 현재 idx
    dfs(idx+2, temp)   # 다음 연산 실행(괄호 없이 순차적으로)

    # 괄호 O
    if idx+2 < n:  # 괄호를 넣고 연산을 할 수 있다면
        temp = calc(ord(arr[idx])-ord('0'), ord(arr[idx+2])-ord('0'), arr[idx+1])  # 괄호 먼저 계산
        temp = calc(before, temp, op)  # 이전 계산값 (연산자) 괄호 계산 값
        dfs(idx+4, temp)  # (idx-1 ~ idx+2) 총 4개 원소 사용


dfs(idx=0, before=0)
print(res)

