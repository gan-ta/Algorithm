import sys
input = sys.stdin.readline

parent = []


def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)

    if a > b:
        parent[a] = b
    else:
        parent[b] = a


def find_parent(a):
    if a == parent[a]:
        return a
    else:
        parent[a] = find_parent(parent[a])
        return parent[a]


if __name__ == '__main__':
    N, M = list(map(int, input().split()))
    parent = [0] * 1001

    edge_list = []

    for i in range(len(parent)):
        parent[i] = i

    for _ in range(M):
        insert = list(map(int, input().split()))
        union_parent(insert[0] - 1, insert[1] - 1)

    res = set()
    for i in range(N):
        res.add(find_parent(i))
    print(len(res))
