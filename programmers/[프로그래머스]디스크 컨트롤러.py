import heapq


def solution(jobs):
    answer = 0
    time = 0
    jobs_len = len(jobs)
    h = []
    jobs.sort(key=lambda x: -x[0])

    search = jobs.pop()
    # 걸리는 시간, 도착 시간
    heapq.heappush(h, [search[1], search[0]])

    while len(h) != 0 or len(jobs) != 0:
        if len(h) != 0:
            search = heapq.heappop(h)
            if search[1] > time:
                time += 1
                heapq.heappush(h, search)
            else:
                time += search[0]
                answer += (time - search[1])
        else:
            time += 1

        # 대기열에서 뽑아옴
        while True:
            if len(jobs) == 0:
                break
            job = jobs.pop()
            if job[0] <= time:
                heapq.heappush(h, [job[1], job[0]])
            else:
                jobs.append(job)
                break

    return int(answer / jobs_len)
