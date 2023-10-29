def time_to_min(time: str) -> int:
    hour = int(time.split(":")[0])
    minute = int(time.split(":")[1])
    return hour * 60 + minute


def solution(book_time):
    res = {}
    for book in book_time:
        start_time = time_to_min(book[0])
        end_time = time_to_min(book[1])
        for time in range(start_time, end_time + 10):
            if res.get(time) is None:
                res[time] = 1
            else:
                res[time] += 1

    return max(res.values())
