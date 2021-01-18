def solution(files):
    answer_list = []

    for i, file in enumerate(files):
        check = 0
        head = ''
        number = ''
        for c in file:
            if check == 0 and not c.isdigit():
                head += c
            elif check == 0 and c.isdigit():
                number += c
                check = 1
            elif check == 1 and c.isdigit():
                number += c
            elif check == 1 and not c.isdigit():
                break
        answer_list.append([head.upper(), int(number), i, file])
    answer_list.sort(key=lambda x: (x[0], x[1], x[2]))

    return [answer[3] for answer in answer_list]