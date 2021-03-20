from collections import defaultdict
if __name__ == '__main__':
    N = int(input())
    str_list = []
    alpha_dict = defaultdict(int)
    ans = 0

    for i in range(N):
        temp = input()
        str_list.append(temp)

    for s in str_list:
        for i,c in enumerate(s):
            alpha_dict[c] += 10**(len(s) - (i+1))

    alpha_list = list(alpha_dict.items())
    alpha_list.sort(key = lambda x : x[1], reverse = True)
    temp = 9
    for v in alpha_list:
        ans += (temp * v[1])
        temp -= 1
    print(ans)

