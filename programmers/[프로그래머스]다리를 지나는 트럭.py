from collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 0

    status = deque()
    trucks = deque()
    weight_status = 0
    total = len(truck_weights)
    count = 0

    for num in truck_weights:
        trucks.appendleft(num)

    while count < total:

        # 도착한 트럭 제외
        idx = 0
        aim = len(status)
        while idx != aim:
            temp = status.pop()
            count += 1
            idx += 1
            weight_status -= temp[0]
            if temp[1] < bridge_length:
                status.append(temp)
                count -= 1
                weight_status += temp[0]
                break

        if len(trucks) != 0:
            search_truck = trucks.pop()

            # 다리에 실을 수 있으면 실음
            if search_truck + weight_status <= weight:
                status.appendleft([search_truck, 0])
                weight_status += search_truck
            else:
                trucks.append(search_truck)

        # 다리에 있는 트럭을 보냄
        idx = 0
        aim = len(status)
        while idx != aim:
            temp = status.pop()
            status.appendleft([temp[0], temp[1] + 1])
            idx += 1

        answer += 1

    return answer
