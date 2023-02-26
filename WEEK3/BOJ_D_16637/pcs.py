"""
[BOJ] 16637_괄호 추가하기
23.02.26

괄호 넣지 않고 계산, 괄호 넣고 계산

"""

n = int(input())
arr = list(input())
res = -1e9


def calc(a, b, op):
    if op == '+':
        return a + b
    elif op == '*':
        return a * b
    elif op == '-':
        return a - b


def dfs(idx, before):
    global res
    if idx >= n:
        res = max(res, before)
        return

    temp = 0
    op = '+' if idx<2 else arr[idx-1]

    # 괄호 X
    temp = calc(before, ord(arr[idx])-ord('0'), op)
    dfs(idx+2, temp)

    # 괄호 O
    if idx+2 < n:
        temp = calc(ord(arr[idx])-ord('0'), ord(arr[idx+2])-ord('0'), arr[idx+1])
        temp = calc(before, temp, op)
        dfs(idx+4, temp)


dfs(idx=0, before=0)
print(res)

