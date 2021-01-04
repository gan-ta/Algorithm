def solution(d, budget):
    answer = 0
    d.sort()

    for num in d:
        if budget - num >= 0:
            budget -= num
            answer += 1
        else:
            break

    return answer
