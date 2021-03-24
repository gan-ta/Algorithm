if __name__ == '__main__':
    N = int(input())
    num_arr = [int(input()) for _ in range(N)]
    arr1 = [i for i in num_arr if i > 1]
    arr2 = [i for i in num_arr if i < 1]
    ans = 0
    one_check = num_arr.count(1)

    arr1.sort(key=lambda x: -x)
    arr2.sort(key=lambda x: x)

    if len(arr1) == 1:
        ans += arr1[-1]
    else:
        for i in range(0, len(arr1), 2):
            if i == len(arr1) - 1:
                break
            ans += (arr1[i] * arr1[i + 1])

        if len(arr1) % 2 == 1:
            ans += arr1[-1]

    if len(arr2) == 1:
        ans += arr2[-1]
    else:
        for i in range(0, len(arr2), 2):
            if i == len(arr2) - 1:
                break
            ans += (arr2[i] * arr2[i + 1])
        if len(arr2) % 2 == 1:
            ans += arr2[-1]

    ans += one_check

    print(ans)
