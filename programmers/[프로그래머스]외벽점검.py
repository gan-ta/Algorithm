from itertools import permutations


def solution(n, weak, dist):
    weak_len = len(weak)
    dist_len = len(dist)
    linear_weak = weak + [w + n for w in weak] # 대칭일 경우 linear하게 펴준는 아이디어

    for pick in range(0, dist_len + 1):
        for p_dists in permutations(dist, pick): # 순열 사용
            for i, start in enumerate(weak):
                point = start

                for distance in p_dists:
                    point += distance
                    if point < linear_weak[i + weak_len - 1]:
                        for search in linear_weak[i + 1: i + weak_len]:
                            if search > point:
                                point = search
                                break
                    else:
                        return pick

    return -1


if __name__ == '__main__':
    print(solution(12, [1, 3, 4, 9, 10], [3, 5, 7]))
