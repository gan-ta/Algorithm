def solution(s):
    stack = list()

    for c in s:
        if c == '(':
            stack.append(c)
        elif c == ')':
            if len(stack) == 0:
                return False
            stack.pop()

    if len(stack) == 0:
        return True
    else:
        return False
