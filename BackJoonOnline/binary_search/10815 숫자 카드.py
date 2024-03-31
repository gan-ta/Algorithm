

if __name__ == '__main__':
    N = int(input())
    cards = list(map(int, input().split(" ")))
    M = int(input())
    find = list(map(int, input().split(" ")))

    res = []

    sorted_cards = sorted(cards)

    for f in find:
        low = 0
        high = len(sorted_cards) - 1

        while True:
            if low > high:
                res.append("0")
                break
            mid = (low + high) // 2

            if f == sorted_cards[mid]:
                res.append("1")
                break
            elif f > sorted_cards[mid]:
                low = mid + 1
            else:
                high = mid - 1

    print(" ".join(res))


