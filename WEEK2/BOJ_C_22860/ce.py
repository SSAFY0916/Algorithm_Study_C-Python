N, M = map(int, input().split())

folder = dict()
file = dict()

for i in range(N + M):
  data = input()
  P = data.split()[0]
  F = data.split()[1]
  isFolder = data.split()[2]

  if isFolder == '1':
    if P not in folder:
      folder[P] = []
      folder[P].append(F)
    elif P in folder:
      folder[P].append(F)
  else:
    if P not in file:
      file[P] = []
      file[P].append(F)
    elif P in file:
      file[P].append(F)

Q = int(input())

for i in range(Q):
  type = []
  count = []
  query = input().split('/')
  route = []
  if len(query) == 1:
    if query[0] in folder:
      for root in folder[query[0]]:
        route.append(root)
      for X in route:
        if X in folder:
          for Y in folder[X]:
            route.append(Y)
    if query[0] in file:
      for X in file[query[0]]:
        count.append(X)
    for X in route:
      if X in file:
        for Y in file[X]:
          count.append(Y)
    type = list(set(count))
    print(len(type), len(count))

  else:
    route = []
    route.append(query[-1])
    for X in route:
      if X in folder:
        for Y in folder[X]:
          route.append(Y)
     
    for X in route:
      if X in file:
        for Y in file[X]:
          count.append(Y)
    type = list(set(count))
    print(len(type), len(count))
