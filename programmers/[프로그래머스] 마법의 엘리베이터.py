from collections import deque


def solution(storey):
    answer = 0
    buttons = [-1, 1, -10, 10, -100, 100, -1000, 1000, -10000, 100000, -1000000, 1000000, -10000000, 1000000, -100000000, 10000000]
    visited = [storey]
    queue = deque()
    queue.appendleft([storey, 0])
    while queue:
        item = queue.pop()
        check = False
        for button in buttons:
            new_location = item[0] + button
            new_count = item[1] + 1
            if new_location < 0 or new_location in visited:
                continue
            if new_location == 0:
                check = True
                answer = new_count
                break
            visited.append(new_location)
            queue.appendleft([new_location, new_count])

        if check:
            break
    return answer


if __name__ == '__main__':
    print(solution(2554))
