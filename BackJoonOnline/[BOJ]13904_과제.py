if __name__ == '__main__':
    N = int(input())
    assign_list = []

    ans = 0
    scores = [0] * 1000

    for _ in range(N):
        d, w = map(int, input().split())
        assign_list.append([d,w])

    assign_list = sorted(assign_list, key = lambda x: (-x[1], x[0]))

    for info in assign_list:
        temp_d, temp_w = info
        temp_d -= 1

        for i in range(temp_d, -1,-1):
            # 과제 수행 할 날짜가 있는 경우
            if scores[i] == 0:
                scores[i] += temp_w
                ans += temp_w
                break

    print(ans)