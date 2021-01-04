from collections import deque


def evaluate(n1, op, n2):
    return eval(str(n1) + op + str(n2))


def calculate_arr():
    num_list = deque()
    op_list = deque()

    num_list.append(int(arr[0]))

    for i in range(1, len(arr)):
        if i % 2 == 0:
            continue

        if bracket_check[i] == 1:
            search = num_list.pop()
            num_list.append(evaluate(search, arr[i], arr[i + 1]))
        else:
            num_list.append(int(arr[i + 1]))
            op_list.append(arr[i])

    while len(op_list) != 0:
        operator = op_list.popleft()
        number1 = num_list.popleft()
        number2 = num_list.popleft()
        num_list.appendleft(evaluate(number1, operator, number2))

    return num_list[0]


def solve(position):
    temp_answer = -pow(2, 31)
    if position >= n:
        return calculate_arr()

    bracket_check[position] = 1  # 괄호를 추가
    temp_answer = max(temp_answer, solve(position + 4))
    bracket_check[position] = 0  # 괄호 추가 안함
    temp_answer = max(temp_answer, solve(position + 2))
    return temp_answer


if __name__ == '__main__':
    n = int(input())
    arr = input()
    bracket_check = [0] * n
    answer = solve(1)
    print(answer)
