res = set()

for _ in range(10):
    num = int(input())
    res.add(num % 42)

print(len(res))