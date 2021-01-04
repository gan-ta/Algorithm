from collections import deque


def solution(cacheSize, cities):
    answer = 0

    q = deque(maxlen=cacheSize)

    for city in cities:
        city = city.upper()
        if city in q:
            q.remove(city)
            q.appendleft(city)
            answer += 1
        else:
            q.appendleft(city)
            answer += 5

    return answer