global answer


def check_quad(sr, sc, length, arr):
    temp = 2

    if length == 1:
        return [True, arr[sr][sc]]

    for r in range(sr, sr + length):
        for c in range(sc, sc + length):
            if temp == 2:
                temp = arr[r][c]
            else:
                if temp != arr[r][c]:
                    return [False, temp]
    return [True, temp]


def search_quad(sr, sc, length, arr):
    global answer

    result = check_quad(sr, sc, length, arr)

    if result[0]:
        answer[result[1]] += 1
    else:
        div_length = length // 2
        search_quad(sr, sc, div_length, arr)
        search_quad(sr + div_length, sc, div_length, arr)
        search_quad(sr, sc + div_length, div_length, arr)
        search_quad(sr + div_length, sc + div_length, div_length, arr)


def solution(arr):
    global answer
    answer = [0, 0]

    search_quad(0, 0, len(arr), arr)

    return answer