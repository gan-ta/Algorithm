def solution(skill, skill_trees):
    answer = 0

    for skill_tree in skill_trees:
        stack = []
        check = ''
        for c in skill_tree:
            if c in list(skill):
                stack.append(c)

        while len(stack) != 0:
            check += stack.pop()

        check = check[::-1]

        skill_idx = 0
        check_idx = 0
        answer_check = 0
        while check_idx != len(check):
            if skill[skill_idx] != check[check_idx]:
                answer_check = 1
                break
            else:
                check_idx += 1
                skill_idx += 1
        if answer_check == 0:
            answer += 1

    return answer
