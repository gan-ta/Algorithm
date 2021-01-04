from itertools import combinations


def solution(relation):
    answer = 0

    # 이미 정해진 후보키 저장
    key_index_list = []
    col_count = len(relation[0])
    pick_index = [i for i in range(0, col_count)]
    super_key = []
    candidate_key = []

    for i in range(1, len(pick_index) + 1):
        for pick in combinations(pick_index, i):
            check = 0
            # step1
            check_set = list()
            for row in relation:
                search = [s for idx, s in enumerate(row) if idx in pick]
                if search in check_set:
                    check = 1
                    break
                else:
                    check_set.append(search)
            if check == 1:
                continue

            # step2
            super_key.append(set(pick))

    for search_super in super_key:
        check = 0
        for search_candidate in candidate_key:
            if search_candidate.issubset(search_super):
                check = 1
                break
        if check == 0:
            candidate_key.append(search_super)

    return len(candidate_key)