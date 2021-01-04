def solution(s):
    answer_list = []
    answer = []
    s = s[1:len(s) - 1]

    stack1 = []
    stack2 = []

    insert_num = ''

    for c in s:
        if c == "{":
            stack1.append("{")
        elif c == "}":
            stack2.append(int(insert_num))
            answer_list.append(stack2)
            stack2 = []
            insert_num = ''
            stack1.pop()
        elif c.isdigit():
            insert_num += c
        elif c == ',':
            if len(stack1) == 0:
                pass
            else:
                stack2.append(int(insert_num))
                insert_num = ''

    answer_list.sort(key=lambda x: len(x))

    for pick in answer_list:
        for num in pick:
            if num not in answer:
                answer.append(num)
                break

    return answer