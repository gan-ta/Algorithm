from collections import deque

if __name__ == '__main__':
    num = int(input())

    q = deque()

    num_list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    answer = -1
    count = 0

    if count == num:
        print(0)
    else:
        for number in num_list[1:]:
            q.appendleft(str(number))

        while len(q) != 0:
            search = q.pop()
            count += 1
            if count == num:
                answer = int(search)
                break

            for number in num_list:
                if int(search[-1]) > number:
                    q.appendleft(search + str(number))
                else:
                    break
        print(answer)
