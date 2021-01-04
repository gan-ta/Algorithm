# 최대공약수 - 유클리드 호제법
# 최소공배수 - 두 수의 곱/ 두 수의 최대공약수

def gcd(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r

    return a


def lcm(a, b):
    return a * b / gcd(a, b)


def solution(arr):
    answer = arr[0]

    for i in range(1, len(arr)):
        answer = lcm(answer, arr[i])

    return answer
