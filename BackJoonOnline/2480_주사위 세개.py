if __name__ == '__main__':
    a, b, c = list(map(int, input().split()))

    if a == b and b == c:
        print(10000 + a * 1000)
    elif a == b and b != c:
        print(1000 + a * 100)
    elif a == c and c != b:
        print(1000 + a * 100)
    elif b == c and a != b:
        print(1000 + b * 100)
    else:
        print(max(max(a, b), c) * 100)
