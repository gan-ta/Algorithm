def solution(number, k):
    answer = ''
    temp_k = 0

    number = [int(i) for i in number]

    stack = list()
    stack.append(number[0])

    # number의 자리가 1일 경우 고려
    if len(number) == 1 and k == 1:
        stack.pop()

    for value in number[1:]:
        while True:
            if len(stack) == 0 or temp_k == k:
                break
            search = stack.pop()
            if search < value:
                temp_k += 1
                continue
            else:
                stack.append(search)
                break
        stack.append(value)

    for i, n in enumerate(stack):
        if i == len(number) - k:
            break
        answer += str(n)

    return answer
