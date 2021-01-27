if __name__ == '__main__':
    N, L = list(map(int, input().split()))
    search_point = list(map(int, input().split()))

    search_point.sort()

    point = search_point[0]
    answer = 1

    for num in search_point[1:]:
        if point + (L - 1) < num:
            answer += 1
            point = num
        else:
            pass

    print(answer)
