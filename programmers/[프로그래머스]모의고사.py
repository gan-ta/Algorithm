def solution(answers):
    p1 = [1, 2, 3, 4, 5]
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    results = [0, 0, 0]

    for i, answer in enumerate(answers):
        if p1[i % len(p1)] == answer:
            results[0] += 1
        if p2[i % len(p2)] == answer:
            results[1] += 1
        if p3[i % len(p3)] == answer:
            results[2] += 1

    num = max(results)

    answer = []
    for i, result in results:
        if num == result:
            answer.append(i+1)
    return answer
