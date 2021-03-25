r_dir = [-1, 0, 1]
c_dir = [1, 1, 1]


def dfs(r, c):
    maps[r][c] = 'x'
    if c == C - 1:
        return True

    for dr, dc in zip(r_dir, c_dir):
        nr = r + dr
        nc = c + dc

        if 0 <= nr < R and 0 <= nc < C and maps[nr][nc] == ".":
            if dfs(nr, nc):
                return True
    return False


if __name__ == '__main__':
    R, C = list(map(int, input().split()))
    maps = []

    for _ in range(R):
        arr = list(input())
        maps.append(arr)

    ans = 0
    for v in range(R):
        if dfs(v, 0):
            ans += 1
    print(ans)
