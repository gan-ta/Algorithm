def solution(relation):
    answer = []

    uid_list = list()
    action_list = list()

    name_dict = dict()

    for i in range(0, len(relation)):
        search_list = relation[i].split(' ')
        if search_list[0] == 'Enter':
            name_dict[search_list[1]] = search_list[2]
            uid_list.append(search_list[1])
            action_list.append("님이 들어왔습니다.")
        elif search_list[0] == "Leave":
            uid_list.append(search_list[1])
            action_list.append("님이 나갔습니다.")
        else:
            name_dict[search_list[1]] = search_list[2]

    for i in range(0, len(uid_list)):
        answer.append(name_dict[uid_list[i]] + action_list[i])

    return answer


if __name__ == '__main__':
    print(solution(
        ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]))
