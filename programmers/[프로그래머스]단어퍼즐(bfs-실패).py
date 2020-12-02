from queue import Queue


def solution(strs, t):
    answer = -1
    check = 0
    q = Queue()

    for word in strs:
        #유망답 아니면 커트
        if not t.startswith(word):
            continue
        # 길이 넘어가면 커트
        if len(word) > len(t):
            continue
        if word == t:
            answer = 1
            check = 1
        q.put([word, 1])

    if check == 0:
        while not q.empty():
            search = q.get()

            # 답이면 도출
            if search[0] == t:
                answer = search[1]
                break

            for word in strs:
                #유망답 아니면 커트
                if not t.startswith(search[0] + word):
                    continue
                # 길이 넘어가면 커트
                if len(search[0] + word) > len(t):
                    continue
                q.put([search[0] + word, search[1] + 1])

    return answer


if __name__ == '__main__':
    print(solution(['ba', 'na', 'n', 'a'], "banana"))
