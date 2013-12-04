import random

f = open("num.data", "w")
n = 10 ** 7
x = []
for i in xrange(n):
  x.append(i)
for i in xrange(n):
  r = random.randint(i, n - 1)
  x[i], x[r] = x[r], x[i]
  f.write("{}\n".format(x[i]))
f.close()
