"""
[BOJ] 1561 놀이공원
23.03.05 PCS
이분탐색, 매개탐색
"""

def main():
    n, m = map(int,input().split())  # n 최대 20억  / m 최대 1만
    arr = list(map(int, input().split()))  # 0번 부터 m번까지 번호
    if n < m:  # (인원수 < 놀이기구 수) -> 마지막 사람의 번호
        print(n)
        return

    left = 0
    right = int(30 * n)
    time = right
    # 마지막 아이가 타는 시간
    while left <= right:
        mid = (left+right)//2

        riding = m  # 탑승인원 - 처음 모두 탑승
        for i in range(m):
            # 각 놀이기구 mid 시간동안 처리할 수 있는 최대 인원수
            riding += mid // arr[i]

        if riding >= n:  # 더 많이 할 수 있다면
            right = mid-1
            time = min(mid, time)
        elif riding < n:  # 부족하다면
            left = mid+1

    riding = m  # 맨 처음 전부 탑승
    for i in range(m):  # 총 걸리는 시간에서 1분 전에 탑승 인원을 체크한다.
        riding += ((time-1)//arr[i])
    for i in range(m):
        if time % arr[i] == 0:  # 총 탑승 시간에 나누어 떨어지는 놀이기구 있으면 ++
            riding+=1
        if riding == n:
            print(i+1)
            return


main()