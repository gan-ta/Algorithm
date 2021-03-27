from collections import defaultdict

if __name__ == '__main__':
    N = int(input())
    city_len = [0] + list(map(int, input().split()))
    city =  list(map(int, input().split()))

    ans_dict = defaultdict(int)
    temp = city[0]

    for i in range(1,len(city)):
        ans_dict[temp] += city_len[i]
        if temp > city[i]:
            temp = city[i]

    ans = 0
    for k in ans_dict.keys():
        ans += (k * ans_dict[k])

    print(ans)