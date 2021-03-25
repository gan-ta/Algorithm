if __name__ == '__main__':
    N, K = list(map(int, input().split()))
    num = input()

    s = [num[0]]
    remove_count = 0

    for i in range(1, len(num)):

        if remove_count == K:
            s += num[i:]
            break

        while True:

            if len(s) == 0:
                s.append(num[i])
                break
            elif num[i] > s[-1]:
                s.pop()
                remove_count += 1
            else:
                s.append(num[i])
                break

            if remove_count == K:
                s.append(num[i])
                break

    ans = ''.join(s[:N - K])
    print(ans)
