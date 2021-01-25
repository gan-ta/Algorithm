import re

if __name__ == '__main__':
    search_str = input()

    num_list = re.split('[+ -]', search_str)
    op_list = re.split('[0-9]', search_str)

    new_search_str = ''

    op_list_len = len(op_list)

    #전처리 작업
    for _ in range(op_list_len):
        if '' in op_list:
            op_list.remove('')

    for i in range(len(num_list)):
        if i != (len(num_list) -1):
            new_search_str += (str(int(num_list[i])) + op_list[i])
        else :
            new_search_str += str(int(num_list[i]))

    #연산수행
    num_list = re.split('[-]', new_search_str)
    new_num_list = [eval(s) for s in num_list if s != '']

    if len(new_num_list) < 1:
        print(0)
    else:
        answer = new_num_list[0]

        for i in range(1,len(new_num_list)):
            answer -= new_num_list[i]

        print(answer)
