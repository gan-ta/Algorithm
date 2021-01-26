if __name__ == '__main__':
    money = 1000 - int(input())
    answer = 0

    a = [500,100,50,10,5,1]

    for num in a:
        answer += money // num
        money %= num

    print(answer)
