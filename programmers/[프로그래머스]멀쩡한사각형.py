def gcd(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


def solution(w, h):
    return (w * h) - (((h / gcd(w, h)) + (w / gcd(w, h)) - 1) * gcd(w, h))