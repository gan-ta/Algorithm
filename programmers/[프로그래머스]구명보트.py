def solution(people, limit):
    answer = 0

    people.sort()

    start_point = 0
    end_point = len(people) - 1
    answer += 1

    while start_point < end_point:

        if people[start_point] + people[end_point] < limit:
            people[end_point] += people[start_point]
            start_point += 1
            continue

        if people[start_point] + people[end_point] == limit:
            start_point += 1
            end_point -= 1
            if start_point <= end_point:
                answer += 1
            continue

        if people[start_point] + people[end_point] > limit:
            end_point -= 1
            answer += 1
            continue

    return answer
