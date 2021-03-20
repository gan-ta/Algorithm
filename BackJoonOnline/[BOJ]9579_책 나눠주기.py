if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, M = list(map(int, input().split()))
        arr_list = []
        ans = 0
        for i in range(M):
            a, b = list(map(int, input().split()))
            arr_list.append((a, b))
        arr_list.sort(key = lambda x: x[1])
        book_set = set()
        for search in arr_list:
            for i in range(search[0], search[1] + 1):
                if i not in book_set:
                    book_set.add(i)
                    ans += 1
                    break
        print(ans)
