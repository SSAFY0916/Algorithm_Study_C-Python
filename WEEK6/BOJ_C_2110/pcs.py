"""
[BOJ] 2110 공유기 설치
23.03.19 pcs
"""

"""
C개 공유기 - N개 집에 적당히 설치, 
가장 인접한 두 공유기 사이 거리를 최대로 하는 프로그램

"""

n, c = map(int, input().split())
house = []
for i in range(n):
    house.append(int(input()))
ans = -1
house.sort()

def binary_search():
    global ans
    # 이분탐색 - 정답을 X라고 가정하고 진행
    # 이 문제에서 정답은 가장 인접한 공유기 사이의 최대 거리를 X라고 가정한다.
    left = 1  # 최소 값
    right = house[n-1] - house[0]  # 최대 값
    while left <= right:
        mid = (left + right) // 2
        curr = house[0]  # 현재위치
        count = 1

        for i in range(1, len(house)):
            if house[i] >= curr + mid:  # 거리가 mid보다 클 때 공유기 설치 가능
                curr = house[i]
                count += 1

        if count >= c:  # 더 많이 설치했다면 (거리증가)
            left = mid+1
            ans = mid
        else:  # 더 적게 설치했다면 (거리감소)
            right = mid-1


binary_search()
print(ans)