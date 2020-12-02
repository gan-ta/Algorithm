def solution(strs, t):
    dp = [20001] * len(t)

    for i in range(0, len(t)):
        for k in range(0, 5):
            if i - k < 0:
                continue
            elif i - k == 0:
                if t[0:i+1] in strs:
                    dp[i] = 1
            else:
                if t[i - k:i+1] in strs:
                    dp[i] = min(dp[i], dp[i - (k+1)] + 1)

    if dp[-1] == 20001:
        return -1
    else:
        return dp[-1]


if __name__ == '__main__':
    print(solution(["app", "ap", "p", "l", "e", "ple", "pp"], "apple"))
