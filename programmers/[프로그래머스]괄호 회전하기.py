from collections import deque


def solution(s):
    answer = 0

    pair_dict = {'[': ']', '{': '}', '(': ')'}
    open_chr = ['[', '{', '(']
    close_chr = [']', '}', ')']

    dq = deque(s)

    for i in range(len(dq)):
        flag = True

        # 문자열 맞춰줌
        temp = dq.popleft()
        dq.append(temp)

        check = list(dq)
        s = []

        for j in check:
            # 스택이 비어 있을 때
            if len(s) == 0:
                if j in open_chr:
                    s.append(j)
                    continue
                else:
                    flag = False
                    break

            if pair_dict[s[-1]] == j:
                s.pop()
                continue
            elif j in open_chr:
                s.append(j)
                continue
            else:
                flag = False
                break

        if len(s) == 0 and flag:
            answer += 1

    return answer