
def check(pattern_split, str)->bool:

    if pattern_split[0] != str[:len(pattern_split[0])] : return False

    str = str[len(pattern_split[0]):]

    if pattern_split[1] != str[len(str) - len(pattern_split[1]):len(str)] : return False

    return True

if __name__ == '__main__':
    n = int(input())
    pattern = input()
    strarr = list()

    for i in range(0,n):
        temp = input()
        strarr.append(temp)

    pattern_split = pattern.split('*')

    for i in range(0,n):
        bool_check = check(pattern_split,strarr[i])
        if bool_check == True:
            print('DA')
        else:
            print('NE')




