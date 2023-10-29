students = set([i + 1 for i in range(30)])

for i in range(28):
    num = int(input())
    students.remove(num)

for student in students:
    print(student)