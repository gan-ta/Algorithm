def solution(phone_book):
    answer = True
    phone_dict = {}

    for phone_num in phone_book:
        phone_dict[phone_num] = 1

    for phone_num in phone_book:
        for i in range(1, len(phone_num)):
            num_split = phone_num[:i]
            if num_split in phone_dict.keys():
                return False

    return answer
