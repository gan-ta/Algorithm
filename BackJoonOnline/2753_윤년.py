def is_leap_year(year: int):
    if year % 4 == 0:
        if (year % 100 != 0) or (year % 400 == 0):
            return True
    return False


if __name__ == '__main__':
    year = int(input())

    if is_leap_year(year):
        print("1")
    else:
        print("0")
