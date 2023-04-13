# (골드 4) 6497 : 전력난
# https://www.acmicpc.net/problem/6497
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


while True:
    m, n = map(int, input().split())  # m : 집의 수, n : 길의 수
    if m == 0 and n == 0:
        break
        
    edges = [list(map(int, input().split())) for _ in range(n)]
    edges.sort(key=lambda a: (a[-1]))  # 가중치 기준으로 정렬

    result = 0  # 절약할 수 있는 비용
    parent = [i for i in range(m)]

    for a, b, z in edges:
        if find_parent(parent, a) == find_parent(parent, b):  # 이미 연결되어 있다면
            result += z
        else:  # 연결되어 있지 않다면
            union(parent, a, b)  # 연결

    print(result)
