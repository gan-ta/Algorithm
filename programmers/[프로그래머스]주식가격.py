def solution(prices):
    answer = [0] * len(prices)

    stack = list()

    for i, value in enumerate(prices):

        if len(stack) == 0:
            stack.append([i, value])

        while len(stack) != 0:
            search = stack.pop()
            if search[1] > value:
                answer[search[0]] = i - search[0]
            else:
                stack.append(search)
                stack.append([i, value])
                break

            if len(stack) == 0:
                stack.append([i, value])

    while len(stack) != 0:
        search = stack.pop()
        answer[search[0]] = len(prices) - 1 - search[0]

    return answer


