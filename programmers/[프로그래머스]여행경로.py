from collections import defaultdict

def solution(tickets):
    answer = []
    graph = defaultdict(lambda : [])

    for ticket in tickets:
        graph[ticket[0]].append(ticket[1])

    #알파벳 순서로 접근을 하기 위해
    for k,v in graph.items():
        v.sort(reverse = True)

    stack = ["ICN"]

    #모든 행선지를 다 거쳐야 함
    while len(stack) != 0:
        search = stack[-1]

        #만약 더 이상 갈 곳이 없다면 정답 리스트에 저장
        if len(graph[search]) == 0:
            answer.append(stack.pop())
        else:
            #갈 경로가 있으면 알파벳이 낮은 순서대로 방문
            stack.append(graph[search].pop())
    answer.reverse()
    return answer
