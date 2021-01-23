def solution(routes):
    answer = 1

    routes.sort()
    print(routes)

    camera = routes[0][1]

    for i in range(len(routes) - 1):
        if camera > routes[i][1]:
            camera = routes[i][1]
        if camera < routes[i + 1][0]:
            answer += 1
            camera = routes[i + 1][1]

    return answer