def solution(s):
    stack = []
    stack.append(s[0])

    for c in s[1:]:
        if len(stack) == 0:
            stack.append(c)
        elif stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)

    if len(stack) == 0:
        return 1
    else:
        return 0