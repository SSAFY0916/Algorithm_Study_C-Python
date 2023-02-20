"""
23.02.19
22860 폴더정리 (골드 3)
https://www.acmicpc.net/problem/22860

main 폴더의 하위 구조
FolderA B C 폴더
File 1 2 3 파일
파일 이름 같으면 동일 파일
한 폴더 안에 같은 이름 파일 존재 x
쿼리에 대해 폴더와 파일의 정보를 알려주는 프로그램 만들자
"""

n, m = map(int, input().split())
folder = {}
cnt = 0
file_set = set()

for i in range(n+m):
    p, f, c = input().split()
    if p in folder:
        folder[p].append([c, f])
    else:
        folder[p] = [[c, f]]


def dfs(f_name):
    global cnt
    if f_name in folder:  # 폴더가 있다면
        for fn in folder[f_name]:
            if fn[0] == '1':  # 폴더 내에 다른 폴더가 있다면 해당 폴더 검색
                dfs(fn[1])
            else:  # 폴더 내에 파일이 있다면
                cnt += 1  # 파일 개수 추가
                file_set.add(fn[1])  # 파일 종류 추가(set으로 중복제거)
                

# 쿼리 실행
q = int(input())
query = []
for i in range(q):
    temp = input().split('/')
    cnt = 0  # 쿼리마다 초기화
    file_set = set()  # 쿼리마다 초기화
    dfs(temp[len(temp)-1])  # 가장 마지막 folder의 file 개수 검색
    print(len(file_set), cnt)  # 각 쿼리의 폴더의 (파일종류 수, 파일 개수) 출력
