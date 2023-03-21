# (골드 3) 17619 : 개구리 점프
# https://www.acmicpc.net/problem/17619
import sys

input = sys.stdin.readline


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


N, Q = map(int, input().split())
tree = []
parent = [i for i in range(N + 1)]
for i in range(N):
    x1, x2, _ = map(int, input().split())
    tree.append([x1, x2, i + 1])

tree.sort(key=lambda x: (x[0]))  # x1 기준으로 정렬

start1, end1, idx1 = tree[0]
for i in range(1, N):
    start2, end2, idx2 = tree[i]
    if start1 <= start2 <= end1:  # 점프 가능
        union(parent, idx1, idx2)
        if end1 >= end2:
            continue

    start1, end1, idx1 = tree[i]

for _ in range(Q):
    a, b = map(int, input().split())
    print(1 if find_parent(parent, a) == find_parent(parent, b) else 0)
