def solution(s):
    answer = 100000

    length = len(s)
    search_length = int(len(s) / 2) + 2

    for i in range(1, search_length):
        str_list = [s[j:j + i] for j in range(0, length, i)]

        temp_length = len(str_list)
        res = [[str_list[0], 1]]
        for j in range(1, temp_length):
            if res[-1][0] == str_list[j]:
                res[-1][1] += 1
            else:
                res.append([str_list[j], 1])

        temp_answer = sum(len(s) + (len(str(cnt)) if cnt > 1 else 0)for s, cnt in res)

        if temp_answer < answer:
            answer = temp_answer

    return answer


if __name__ == '__main__':
    print(solution("xababcdcdababcdcd"))
