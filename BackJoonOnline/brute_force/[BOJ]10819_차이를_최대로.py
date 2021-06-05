from itertools import permutations

def calc(check_arr):

    res = 0

    for i in range(0,len(check_arr)-1):
        res += abs(check_arr[i] - check_arr[i+1])

    return res


if __name__ == '__main__':
    N = int(input())
    num_list = list(map(int,input().split()))

    ans = -1000
    for check_arr in permutations(num_list,len(num_list)):
        ans = max(ans, calc(check_arr))

    print(ans)