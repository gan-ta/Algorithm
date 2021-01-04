def is_palindrome(str):
    str_len = len(str)
    half_str_len = int(str_len / 2)

    if str_len % 2 == 0:
        if str[:half_str_len] == str[half_str_len:][::-1]:
            return True
    else:
        if str[:half_str_len] == str[half_str_len + 1:][::-1]:
            return True
    return False


def solution(s):
    answer = 1

    s_len = len(s)

    for i in range(s_len, 1, -1):
        search_str = [s[j:j+i] for j in range(0, s_len) if i+j <= s_len]

        for search in search_str:
            if is_palindrome(search):
                answer = i
                break

        if answer != 1:
            break

    return answer


if __name__ == '__main__':
    print(solution("abc"))
