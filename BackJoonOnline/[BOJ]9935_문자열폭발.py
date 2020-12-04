if __name__ == '__main__':
    full_str = input()
    search_str = input()

    stack = []

    #효율1 - 길이는 변수로 뽑기
    full_len = len(full_str)
    search_len = len(search_str)

    #효율2 - 원소 삭제 시에는 del 쓰기!
    for i in range(0, full_len):
        stack.append(full_str[i])
        if ''.join(stack[-search_len:]) == search_str:
            del stack[-search_len:]

    if len(stack) == 0:
        print("FRULA")
    else:
        print(''.join(stack))