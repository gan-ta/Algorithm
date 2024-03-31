visited = [[False for i in range(101)] for j in range(101)]
res = 0


def get_dist(point1, point2):
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])


def dfs(r, c, dist, count):
    global res

    if res < dist:
        return

    if len(points) == count:
        res = min(res, dist + get_dist((r, c), home))
        return

    for point in points:
        if not visited[point[0]][point[1]]:
            visited[point[0]][point[1]] = True
            dfs(point[0], point[1], dist + get_dist((r, c), point), count + 1)
            visited[point[0]][point[1]] = False

#
# import sys
#
# sys.stdin = open("input.txt", "r")

T = int(input())

for test_case in range(1, T + 1):
    res = 200 * 20
    N = int(input())
    temp = list(map(int, input().split()))
    company = (temp[0], temp[1])
    home = (temp[2], temp[3])
    points_list = temp[4:]
    points = []

    for i in range(0, len(points_list), 2):
        points.append((points_list[i], points_list[i + 1]))

    visited[company[0]][company[1]] = True

    dfs(temp[0], temp[1], 0, 0)

    visited[company[0]][company[1]] = False

    print(f"#{test_case} {res}")
