def solution(citations):
    answer = 0
    citations.sort()
    total = len(citations)
    max_citation = max(citations)

    for h in range(max_citation, 0, -1):
        for i in range(0, len(citations)):
            if citations[i] >= h:
                idx = i
                break
        count = total - idx
        if count >= h:
            answer = h
            break

    return answer

