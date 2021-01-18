def solution(n, results):
    answer = 0
    win = [set() for _ in range(n + 1)]
    lose = [set() for _ in range(n + 1)]

    for search in range(1, n + 1):
        for result in results:
            if result[0] == search:
                win[search].add(result[1])
            if result[1] == search:
                lose[search].add(result[0])

        # 누적 사항 조정
        for winner in lose[search]:
            win[winner].update(win[search])
        for loser in win[search]:
            lose[loser].update(lose[search])

    for i in range(1, n + 1):
        if len(win[i]) + len(lose[i]) == n - 1:
            answer += 1

    return answer