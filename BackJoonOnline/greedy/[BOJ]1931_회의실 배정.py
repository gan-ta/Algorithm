import sys

input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input())

    res = []
    end_time = 0

    time_list = []

    for _ in range(N):
        s, e = list(map(int, input().split()))
        time_list.append((s, e))

    time_list.sort(key=lambda x: (x[1], x[0]))

    for time in time_list:
        s, e = time
        if s >= end_time:
            end_time = e
            res.append(time)

    print(len(res))