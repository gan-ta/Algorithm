global check


def dfs(idx, numbers_len_, value_, target_, numbers_):
    global check

    if idx == numbers_len_:
        if value_ == target_:
            check += 1
        return

    dfs(idx + 1, numbers_len_, value_ + numbers_[idx], target_, numbers_)
    dfs(idx + 1, numbers_len_, value_ - numbers_[idx], target_, numbers_)


def solution(numbers, target):
    numbers_len = len(numbers)
    global check
    check = 0

    dfs(0, numbers_len, 0, target, numbers)

    answer = check

    return answer