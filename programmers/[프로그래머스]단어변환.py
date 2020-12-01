from queue import Queue


def comp(str1, str2):
    count = 0
    for i in range(0, len(str1)):
        if str1[i] != str2[i]:
            count += 1
    if count == 1:
        return True
    else:
        return False


def solution(begin, target, words):
    answer = 0
    q = Queue()
    # 문자열, depth
    q.put([begin, 0])
    visited = [0] * len(words)

    while not q.empty():
        search = q.get()

        if search[0] == target:
            if answer == 0:
                answer = search[1]
            else:
                if answer > search[1]:
                    answer = search[1]

        for i in range(0, len(words)):
            if comp(search[0], words[i]) and visited[i] == 0:
                visited[i] = 1
                q.put([words[i], search[1] + 1])

    return answer


if __name__ == '__main__':
    print(solution("hit", "cog", ['hot', 'dot', 'dog', 'lot', 'log']))
