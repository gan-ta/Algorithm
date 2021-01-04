def check_correct(str_):
    stack = []

    for c in str_:
        if c == '(':
            stack.append('(')
        else:
            if len(stack) == 0:
                return False
            stack.pop()
    return True


def step(str_):
    ret = ''
    if str_ == '':
        return ''

    idx = -1

    for i in range(1, len(str_) + 1):
        if str_[:i].count('(') == str_[:i].count(')'):
            idx = i
            break

    if idx == -1:
        idx = len(str_)

    u, v = str_[:idx], str_[idx:]

    if check_correct(u):
        ret = u + step(v)
    else:
        u = u[1:]
        u = u[:len(u) - 1]
        ru = ''
        for cu in u:
            if cu == '(':
                ru += ')'
            else:
                ru += '('
        ret = '(' + step(v) + ')' + ru

    return ret


def solution(p):
    answer = ''

    if p == '':
        return ''
    else:
        answer = step(p)

    return answer