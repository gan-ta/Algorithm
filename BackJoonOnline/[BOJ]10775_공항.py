if __name__ == '__main__':
    G = int(input())
    P = int(input())
    p_list = [int(input()) for _ in range(P)]
    parent = [p for p in range(G+1)]

    def find(p):
        if parent[p] == p:
            return p
        parent[p] = find(parent[p])
        return parent[p]

    def union(a,b):
        a_parent = find(a)
        b_parent = find(b)
        parent[b_parent] = a_parent

    ans = 0
    for v in p_list:
        v_parent = find(v)

        if v_parent == 0:
            break

        ans += 1
        union(v_parent-1, v_parent)
    print(ans)


