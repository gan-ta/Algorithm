from itertools import combinations

if __name__ == '__main__':

    while True:
        num_list = list(map(int,input().split()))

        if num_list[0] == 0:
            break

        num = num_list[0]
        num_list = num_list[1:]
        num_list.sort()
        pick_list = [i for i in range(num)]

        for check in combinations(pick_list,6):
            temp = ""
            for idx in check:
                temp += str(num_list[idx]) + " "
            temp = temp.strip()
            print(temp)
        print()
