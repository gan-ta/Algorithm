if __name__ == '__main__':
    N = int(input())
    room_arr = [tuple(map(int, input().split())) for _ in range(N)]

    room_arr.sort(key=lambda x: (x[1], x[0]))

    search = room_arr[0]
    ans = 1

    for v in room_arr[1:]:
        if v[0] == v[1]:
            ans += 1
            continue

        if search[1] <= v[0]:
            ans += 1
            search = v
    print(ans)
