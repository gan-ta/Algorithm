if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        money = int(input())

        q = int(money / 25)
        money -= (25 * q)

        d = int(money / 10)
        money -= (10 * d)

        n = int(money / 5)
        money -= (5 * n)

        p = money

        print(f"{q} {d} {n} {p}")


