# (플래티넘 5) 5373 : 큐빙
# https://www.acmicpc.net/problem/5373
import sys

input = sys.stdin.readline

print = sys.stdout.write


def rotate(data, option=False):  # 단면 회전
    if not option:
        data[0][1], data[1][2], data[2][1], data[1][0] = data[1][0], data[0][1], data[1][2], data[2][1]
        data[0][0], data[0][2], data[2][2], data[2][0] = data[2][0], data[0][0], data[0][2], data[2][2]
    else:
        data[0][1], data[1][2], data[2][1], data[1][0] = data[1][2], data[2][1], data[1][0], data[0][1]
        data[0][0], data[0][2], data[2][2], data[2][0] = data[0][2], data[2][2], data[2][0], data[0][0]
    return data


def simulation():
    n = int(input())
    # U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
    U, D, F, B, L, R = [], [], [], [], [], []
    for _ in range(3):
        U.append(['w'] * 3)  # 윗 면, 흰색
        D.append(['y'] * 3)  # 아랫 면, 노란색
        F.append(['r'] * 3)  # 앞 면, 빨간색
        B.append(['o'] * 3)  # 뒷 면, 오렌지색
        L.append(['g'] * 3)  # 왼쪽 면, 초록색
        R.append(['b'] * 3)  # 오른쪽 면, 파란색

    command = list(input().split())
    for c in command:
        k = 1 if c[1] == '+' else 3
        if c[0] == 'L':
            for _ in range(k):
                temp = [U[0][0], U[1][0], U[2][0]]
                U[0][0], U[1][0], U[2][0] = B[2][0], B[1][0], B[0][0]
                B[0][0], B[1][0], B[2][0] = D[0][0], D[1][0], D[2][0]
                D[0][0], D[1][0], D[2][0] = F[2][0], F[1][0], F[0][0]
                F[0][0], F[1][0], F[2][0] = temp
                L = rotate(L)
        elif c[0] == 'R':
            for _ in range(k):
                temp = [U[0][2], U[1][2], U[2][2]]
                U[0][2], U[1][2], U[2][2] = F[0][2], F[1][2], F[2][2]
                F[0][2], F[1][2], F[2][2] = D[2][2], D[1][2], D[0][2]
                D[0][2], D[1][2], D[2][2] = B[0][2], B[1][2], B[2][2]
                B[0][2], B[1][2], B[2][2] = temp[::-1]
                R = rotate(R)
        elif c[0] == 'F':
            for _ in range(k):
                temp = U[2]
                U[2] = [L[2][2], L[1][2], L[0][2]]
                L[0][2], L[1][2], L[2][2] = D[2]
                D[2] = [R[2][0], R[1][0], R[0][0]]
                R[0][0], R[1][0], R[2][0] = temp
                F = rotate(F)
        elif c[0] == 'B':
            for _ in range(k):
                temp = U[0]
                U[0] = [R[0][2], R[1][2], R[2][2]]
                R[0][2], R[1][2], R[2][2] = D[0][::-1]
                D[0] = [L[0][0], L[1][0], L[2][0]]
                L[0][0], L[1][0], L[2][0] = temp[::-1]
                B = rotate(B, True)
        elif c[0] == 'U':
            for _ in range(k):
                temp = [B[0][0], B[0][1], B[0][2]]
                B[0] = [L[0][2], L[0][1], L[0][0]]
                L[0] = [F[0][0], F[0][1], F[0][2]]
                F[0] = [R[0][0], R[0][1], R[0][2]]
                R[0] = temp[::-1]
                U = rotate(U)
        else:  # c[0] == 'D'
            for _ in range(k):
                temp = [B[2][0], B[2][1], B[2][2]]
                B[2] = [R[2][2], R[2][1], R[2][0]]
                R[2] = [F[2][0], F[2][1], F[2][2]]
                F[2] = [L[2][0], L[2][1], L[2][2]]
                L[2] = temp[::-1]
                D = rotate(D, True)
    print('\n'.join(map(''.join, U)) + '\n')


for _ in range(int(input())):
    simulation()
