def solution(arr1, arr2):
    answer = []
    insert_row = []

    for row1 in arr1:
        insert_row = []
        for i in range(0, len(arr2[0])):
            insert_num = 0
            for j in range(0, len(arr2)):
                insert_num += (row1[j] * arr2[j][i])
            insert_row.append(insert_num)
        answer.append(insert_row)

    return answer