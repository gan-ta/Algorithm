def solution(nums):
    answer_set = set(nums)

    if len(answer_set) >= (len(nums) // 2):
        return len(nums) // 2
    else:
        return len(answer_set)