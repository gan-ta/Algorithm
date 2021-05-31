if __name__ == '__main__':
    N = int(input())
    crane_list = map(int, input().split())

    M = int(input())
    box_list = map(int, input().split())

    crane_list = sorted(crane_list, key = lambda x : -x)
    box_list = sorted(box_list, key = lambda x : -x)

    ans = 0
    flag = False

    while(True):
        if len(box_list) == 0:
            break

        if crane_list[0] < box_list[0]:
            ans = -1
            break
        flag = False
        for crane in crane_list:
            temp = 0

            if len(box_list) == 0:
                ans += 1
                flag = True
                break

            for box in box_list:
                if crane >= box:
                    temp = box
                    break
            # 박스를 없애줌
            if temp != 0:
                box_list.remove(temp)

        if flag:
            break

        ans += 1

    print(ans)

