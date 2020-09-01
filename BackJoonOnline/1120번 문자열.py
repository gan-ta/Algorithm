def compare(a,b) -> int:
    res  = 0
    for i in range(0,len(a)):
        if a[i] != b[i]:
            res += 1

    return res


if __name__== '__main__':
    answer = 100
    total = input()
    total = total.split(' ')
    a = total[0]
    b = total[1]
    _diff = len(b) - len(a)
    for i in range(0, _diff+1):
        check = compare(a,b[i:i+len(a)])

        if answer > check:
            answer = check
    print(answer)


