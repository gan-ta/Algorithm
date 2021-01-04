def is_carpet(brown, yellow, vertical):
    if yellow % vertical != 0:
        return [-1, -1]

    horizontal = int(yellow / vertical)

    if horizontal < vertical:
        return [-1, -1]

    if 2 * (vertical + horizontal) + 4 == brown:
        return [horizontal+2, vertical+2]

    return [-1, -1]


def solution(brown, yellow):
    vertical = 0

    while True:
        vertical += 1
        answer = is_carpet(brown, yellow, vertical)
        if answer[0] != -1:
            break

    return answer


if __name__ == "__main__":
    print(solution(24, 24))
