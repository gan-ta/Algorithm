from itertools import combinations

if __name__ == '__main__':
    check_list = []

    for _ in range(9):
        insert_num = int(input())
        check_list.append(insert_num)

    idx_list = [i for i in range(9)]

    ans_idx = None
    # 7명을 뽑는 경우
    for com_check in combinations(idx_list,7):
        temp_ans = 0
        for check in com_check:
            temp_ans += check_list[check]

        if temp_ans == 100:
            ans_idx = com_check
            break

    ans_list = []
    for idx in ans_idx:
        ans_list.append(check_list[idx])
    ans_list.sort()

    for ans in ans_list:
        print(ans)
