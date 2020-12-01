if __name__ == '__main__':
    input_str = input()
    result = input_str.split(' ')
    print(len(result) - result.count(''))
