def solution(numbers):
    answer = [0 for i in range(len(numbers))]
    stack = []

    for i in range(len(numbers)):
        while stack and numbers[stack[-1]] < numbers[i]:
            answer[stack.pop()] = numbers[i]
        stack.append(i)

    for val in stack:
        answer[val] = -1

    return answer


if __name__ == '__main__':
    print(solution([9, 1, 5, 3, 6, 2]))
