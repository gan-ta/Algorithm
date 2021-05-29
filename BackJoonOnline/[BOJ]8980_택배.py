if __name__ == '__main__':
    N, C = map(int,input().split()) # 마을 수, 트럭의 용량
    M = int(input())

    box_info = []
    load_info = []

    for _ in range(N):
        load_info.append(C)

    for _ in range(M):
        a, b, c = map(int, input().split())
        box_info.append([a,b,c])

    # 도착지 - 출발지
    box_info = sorted(box_info, key = lambda x: (x[1],x[0]))

    ans = 0

    for i in range(len(box_info)):
        start, end, storage = box_info[i]
        start -= 1
        end -= 1

        # 출발지에서 도착지까지
        min_num = min(load_info[start:end])

        if storage < min_num:
            for j in range(start, end):
                load_info[j] -= storage
            ans += storage
        else:
            for j in range(start, end):
                load_info[j] -= min_num
            ans += min_num

    print(ans)
