def solution(s):
    temp_s = list(s.split())
    blank_count = 0
    answer = []
    blank_arr = []

    # 공백 칸을 세어줌
    for i, c in enumerate(s):
        if i == 0 and c != ' ':
            blank_arr.append(0)

        if c == ' ':
            blank_count += 1
        elif c != ' ' and blank_count != 0:
            blank_arr.append(blank_count)
            blank_count = 0

    if blank_count != 0:
        blank_arr.append(blank_count)
    else:
        blank_arr.append(0)

    # 문자열 상태 저장
    for ss in temp_s:
        insert = ss[0:1].upper() + ss[1:].lower()
        answer.append(insert)

    blank_arr_str = [' ' * n for n in blank_arr]
    ret = ''

    for i in range(0, len(answer)):
        ret += (blank_arr_str[i] + answer[i])

    ret += blank_arr_str[-1]

    return ret