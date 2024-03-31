
if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split(" ")))

    lis = [A[0]]

    for a in A[1:]:
        if lis[-1] < a:
            lis.append(a)
        else:
            low = 0
            high = len(lis) - 1
            while True:
                if low >= high:
                    break

                mid = (low + high) // 2

                if lis[mid] < a:
                    low = mid + 1
                else:
                    high = mid

            lis[high] = a

    print(len(lis))
