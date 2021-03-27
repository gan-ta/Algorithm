if __name__ == '__main__':
    N = int(input())
    K = int(input())
    sensor_loc = list(map(int, input().split()))

    sensor_loc.sort()

    sensor_loc_dist = []

    for i, sensor in enumerate(sensor_loc):
        if i == 0:
            temp = sensor
            continue

        sensor_loc_dist.append(sensor - temp)
        temp = sensor

    cnt = 1
    while cnt <= K-1:
        if len(sensor_loc_dist) == 0:
            break
        m = max(sensor_loc_dist)
        sensor_loc_dist.remove(m)
        cnt += 1

    print(sum(sensor_loc_dist))