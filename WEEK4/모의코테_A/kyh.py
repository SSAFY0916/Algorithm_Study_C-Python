# (골드 5) 1148 : 단어 만들기
# https://www.acmicpc.net/problem/1148
import sys
from collections import defaultdict, Counter

input = sys.stdin.readline
dictionary = []
while 1:
    data = input().rstrip()
    if data == '-':
        break
    dictionary.append(data)

while 1:
    puzzle = input().rstrip()
    if puzzle == '#':
        break

    puzzle_counter = Counter(puzzle)
    puzzle_used = defaultdict(int)

    for word in dictionary:
        for w in set(word):
            if w not in puzzle_counter.keys() or puzzle_counter[w] < word.count(w):
                break
        else:
            for w in set(word):
                puzzle_used[w] += 1

    min_, max_ = int(1e9), 0
    min_w, max_w = [], []
    for key in puzzle_counter.keys():
        value = puzzle_used[key]
        if value > max_:
            max_w = [key]
            max_ = value
        elif value == max_:
            max_w.append(key)

        if value < min_:
            min_w = [key]
            min_ = value
        elif value == min_:
            min_w.append(key)

    print(''.join(sorted(min_w)), min_, ''.join(sorted(max_w)), max_)
