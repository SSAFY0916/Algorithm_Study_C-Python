# (골드 2) 3300 : 무어 기계
# https://www.acmicpc.net/problem/3300
import re
import string
import sys

input = sys.stdin.readline
t = int(input())
for _ in range(t):
    data1 = input().rstrip()
    data2 = input().rstrip()

    patternA = '^' + re.sub('_', '[A-Z]+', data1) + '$'
    patternB = '^' + re.sub('_', '', data1) + '$'

    if not re.match(patternA, data2):
        print('!')
    elif re.match(patternB, data2):
        print('_')
    else:
        for alpha in string.ascii_uppercase:
            if re.match('^' + re.sub('_', alpha, data1) + '$', data2):
                print(alpha)
                break
