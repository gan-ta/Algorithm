def calc_dp(n):
    max_value = 0

    for i in range(0, n - len(sub_str) + 1):
        if max_value < dp[i]:
            max_value = dp[i]

    if full_str[n:].startswith(sub_str):
        dp[n] = max_value + 1
    else:
        dp[n] = max_value


if __name__ == '__main__':
    full_str = input()
    sub_str = input()

    dp = [0] * len(full_str)

    for i in range(0, len(full_str)):
        calc_dp(i)

    print(max(dp))
