def solution(weights):
    answer = 0
    positions = [(2, 3), (2, 4), (3, 2), (3, 4), (4, 2), (4, 3)]
    weight_dict = {}

    for w in weights:
        weight_dict.setdefault(w, 0)
        weight_dict[w] += 1

    for w in weights:
        if weight_dict[w] > 1:
            answer += weight_dict[w] * (weight_dict[w] - 1) // 2

        for (left, right) in positions:
            right_weight = w * left / right
            if right_weight in weight_dict:
                answer += weight_dict[w] * weight_dict[right_weight]
        weight_dict[w] = 0

    return answer


if __name__ == '__main__':
    print(solution([100, 180, 360, 100, 270]))
