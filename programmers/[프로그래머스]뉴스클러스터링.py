def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()
    str1_set = []
    str2_set = []

    inter_set = []
    union_set = []

    J = 1

    for i in range(0, len(str1) - 1):
        if 'A' <= str1[i] <= 'Z' and 'A' <= str1[i + 1] <= 'Z':
            str1_set.append(str1[i] + str1[i + 1])

    for i in range(0, len(str2) - 1):
        if 'A' <= str2[i] <= 'Z' and 'A' <= str2[i + 1] <= 'Z':
            str2_set.append(str2[i] + str2[i + 1])

    for s in str1_set:
        if str2_set.count(s) != 0:
            inter_set.append(s)
            union_set.append(s)
            str2_set.remove(s)
        else:
            union_set.append(s)

    for s in str2_set:
        union_set.append(s)

    if len(union_set) != 0:
        J = len(inter_set) / len(union_set)

    return int(J * 65536)
