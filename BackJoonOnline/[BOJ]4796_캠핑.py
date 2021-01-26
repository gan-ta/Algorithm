if __name__ =='__main__':
    idx = 0
    while True:
        idx += 1
        L,P,V = map(int,input().split())

        if L == 0 and P == 0 and V == 0:
            break

        answer = 0
        answer += (V //P) * L
        if (V % P) <= L:
            answer +=  V % P
        else:
            answer +=  L

        print(f"Case {idx}: {answer}")