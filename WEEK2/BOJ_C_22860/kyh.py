# (골드 3) 22860 : 폴더 정리 (small)
# https://www.acmicpc.net/problem/22860

import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())  # n : 폴더의 총 개수, m : 파일의 총 개수
dict_ = dict()

for _ in range(n + m):
    p, f, c = input().split()  # p : 상위 폴더의 이름, f : 폴더 또는 파일의 이름, c : 폴더인지 아닌지
    if p not in dict_:
        dict_[p] = {'file': dict(), 'folder': set()}
    if c == '1':  # 폴더
        dict_[p]['folder'].add(f)
    else:  # 파일
        if f not in dict_[p]['file']:
            dict_[p]['file'][f] = 1
        else:
            dict_[p]['file'][f] += 1

print(dict_)
for _ in range(int(input())):
    query = list(input().rstrip().split('/'))  # 쿼리 / 기준으로 분리
    file_type, file = set(), 0  # 파일 종류, 파일 총 개수
    prev = query[0]  # 상위 폴더
    for q in query[1:]:
        if q not in dict_[prev]['folder']:  # 하위에 해당하는 폴더가 없는 경우
            break  # 종료
        prev = q  # 상위 폴더 현재 폴더로 업데이트
    else:  # break문으로 종료되지 않고 정상적으로 for문을 마쳤다면 주어진 쿼리에 해당하는 경로가 유효
        queue = deque([prev])  # 탐색할 폴더를 담아둠
        while queue:  # 더이상 하위 폴더가 없을 때까지 돌리기
            curr = queue.popleft()
            if curr not in dict_:  # 현재 폴더에 하위 폴더나 파일이 없을 때
                continue
            file_type.update(list(dict_[curr]['file'].keys()))  # 파일 종류 추가
            file += sum(dict_[curr]['file'].values())  # 파일 개수 더하기
            queue += list(dict_[curr]['folder'])  # 탐색할 폴더 목록을 담아둔 queue에 하위 폴더 추가
    print(len(file_type), file)  # 파일의 종류의 개수와 파일의 총 개수를 출력
