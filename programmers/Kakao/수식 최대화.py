import itertools
import re


def plus_operation(numbers,operators):
    re_numbers = [numbers[0]]
    
    for i in range(1,len(numbers)):
        if operators[i-1] != '+':
            re_numbers.append(numbers[i])
        else:
            re_numbers[len(re_numbers) - 1] = \
                str(int(re_numbers[len(re_numbers) - 1]) + int(numbers[i]))
            
    while '+' in operators:
        operators.remove('+')
    
    return re_numbers,operators
    

def minus_operation(numbers,operators):
    re_numbers = [numbers[0]]
    
    for i in range(1,len(numbers)):
        if operators[i-1] != '-':
            re_numbers.append(numbers[i])
        else:
            re_numbers[len(re_numbers) - 1] = \
                str(int(re_numbers[len(re_numbers) - 1]) - int(numbers[i]))
    
    while '-' in operators:
        operators.remove('-')
    
    return re_numbers,operators

def multi_operation(numbers,operators):
    re_numbers = [numbers[0]]
    
    for i in range(1,len(numbers)):
        if operators[i-1] != '*':
            re_numbers.append(numbers[i])
        else:
            re_numbers[len(re_numbers) - 1] = \
                str(int(re_numbers[len(re_numbers) - 1]) * int(numbers[i]))
    
    while '*' in operators:
        operators.remove('*')
    
    return re_numbers,operators

def solution(expression):
    answer = 0
    
    operators = re.split('[0123456789]',expression)
    numbers = re.split('[-*+]',expression)
    while '' in operators:
        operators.remove('')
        
    order = [1, 2, 3]
    re_orders = list(itertools.permutations(order))
    
    for re_order in re_orders:
        _operators = operators.copy()
        _numbers = numbers.copy()
        for i in re_order:
            if i == 1:
                _numbers, _operators = plus_operation(_numbers,_operators)
            elif i == 2:
                _numbers, _operators = minus_operation(_numbers,_operators)
            else:
                _numbers, _operators = multi_operation(_numbers,_operators)
        if answer < abs(int(_numbers[0])):
            answer = abs(int(_numbers[0]))
        
    return answer