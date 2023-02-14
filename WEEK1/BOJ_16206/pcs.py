

n, m = map(int, input().split())
cake = list(map(int, input().split())) # 롤케익 배열
count = 0 # 길이 10짜리 롤케익 수

# 롤케익, 선택, 자르는 함수
def slice_cake():
    global cake, count
    cut = 0
    # 참고한 코드 ******
    cake.sort(key=lambda x: (x%10, x))
    
    for i in range(n):
        while cake[i] >= 10:
            if cake[i] == 10:
                count += 1
                cake[i] = 0
            elif cake[i] == 20:
                count += 2
                cut += 1
                cake[i] = 0
            else:
                count += 1
                cut += 1
                cake[i] -= 10

            if cut >= m:
                print(count)
                return

    print(count)
    return


slice_cake()
