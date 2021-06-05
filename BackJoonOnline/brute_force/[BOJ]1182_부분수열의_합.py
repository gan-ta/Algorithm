if __name__ == '__main__':
    N, S = list(map(int, input().split()))
    num_list = list(map(int, input().split()))
    ans = 0

    for check_num in range(1,pow(2,N)):
        check_idx_list = []
        temp_ans = 0

        # 조합을 뽑아내기
        for _ in range(N):
            check_idx_list.append(check_num % 2)
            check_num = check_num >> 1

        for i,idx in enumerate(check_idx_list):
            if idx == 1:
                temp_ans += num_list[i]

        if temp_ans == S:
            ans += 1

    print(ans)