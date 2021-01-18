import heapq


def solution(operations):
    answer = []

    h = []

    for search in operations:
        a, b = search.split(" ")
        b = int(b)
        if a == 'I':
            heapq.heappush(h, b)
        else:
            if len(h) != 0:
                if b == 1:
                    h.pop(h.index(heapq.nlargest(1, h)[0]))
                else:
                    heapq.heappop(h)
    if len(h) == 0:
        return [0, 0]
    else:
        answer.extend(heapq.nlargest(1, h))
        answer.extend(heapq.nsmallest(1, h))
        return answer