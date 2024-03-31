
if __name__ == "__main__":
    N = int(input())
    solution = list(map(int, input().split(" ")))

    solution.sort()

    left = 0
    right = len(solution) - 1

    ans_dist = 10000000000
    ans = []

    while True:
        if left >= right:
            break

        dist = solution[right] + solution[left]

        if ans_dist > abs(dist):
            ans = [str(solution[left]), str(solution[right])]
            ans_dist = abs(dist)

        if dist < 0:
            left += 1
        else:
            right -= 1

    print(" ".join(ans))
