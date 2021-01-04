from collections import deque
from itertools import combinations

if __name__ == '__main__':
    global visited
    N = int(input())
    num_list = list(map(int, input().split()))
    num_list = [0] + num_list
    total = sum(num_list)
    answer = 1001
    graph = list()
    graph.append([])
    start = 0

    for i in range(N):
        graph.append(list(map(int, input().split()[1:])))

    node_list = [c for c in range(N + 1)]

    q = deque()

    for i in range(1, N):
        for com_list in combinations(node_list, i):

            visited = [0] * (N + 1)
            visited[0] = 1
            check1 = False
            check2 = False

            for com_num in com_list:
                visited[com_num] = 1

            for j in range(1, N + 1):
                if visited[j] == 0:
                    start = j
                    break

            visited[start] = 1
            q.appendleft(start)

            while len(q) != 0:
                search = q.pop()
                for check in graph[search]:
                    if visited[check] == 0:
                        visited[check] = 1
                        q.appendleft(check)

            if visited.count(0) == 0:
                check1 = True

            visited = [1] * (N + 1)

            for com_num in com_list:
                visited[com_num] = 0

            visited[0] = 1
            visited[com_list[0]] = 1
            q.appendleft(com_list[0])

            while len(q) != 0:
                search = q.pop()
                for check in graph[search]:
                    if visited[check] == 0:
                        visited[check] = 1
                        q.appendleft(check)

            if visited.count(0) == 0:
                check2 = True

            if check1 and check2:
                group1 = sum([num_list[n] for n in com_list])
                group2 = total - group1
                answer = min(answer, abs(group1 - group2))

    if answer == 1001:
        answer = -1
    print(answer)
