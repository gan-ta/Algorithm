def solution(n, words):
    answer = [0, 0]

    answer_dict = {}

    for i, word in enumerate(words):
        turn_num = (i // n) + 1
        people_num = (i % n) + 1

        if word in answer_dict.keys():
            return [people_num, turn_num]

        if i != 0 and word[0] != words[i - 1][-1]:
            return [people_num, turn_num]

        answer_dict[word] = 1

    return answer
