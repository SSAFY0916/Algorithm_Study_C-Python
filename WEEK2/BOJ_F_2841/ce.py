import sys

N, P = map(int, sys.stdin.readline().split())
data = dict()

for i in range(6):
  data[i + 1] = []

count = 0

for i in range(N):
  line, flat = map(int, sys.stdin.readline().split())

  if len(data[line]) > 0 and data[line][-1] == flat:
    continue

  elif len(data[line]) > 0 and data[line][-1] > flat:
    while True:
      if len(data[line]) > 0 and data[line][-1] > flat:
        data[line].pop()
        count += 1
      elif len(data[line]) > 0 and data[line][-1] == flat:
        break
      elif len(data[line]) == 0 or data[line][-1] < flat:
        data[line].append(flat)
        count += 1
        break
        
  elif len(data[line]) == 0 or data[line][-1] < flat:
    data[line].append(flat)
    count += 1

print(count)
