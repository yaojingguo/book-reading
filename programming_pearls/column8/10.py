import sys

def nearest_to_zero(A):
  n = len(A)
  p = [[0, i] for i in xrange(n + 1)]
  for i in xrange(1, n + 1):
    p[i][0] = p[i - 1][0] + A[i - 1]
  p.sort(key = lambda x : x[0])
  nearest = sys.maxint
  pos = (None, None)
  for i in xrange(n):
    diff = p[i + 1][0] - p[i][0]
    if nearest > diff:
      nearest = diff
      pos = (p[i][1], p[i][1])
  pos = (min(pos), max(pos))
  return (nearest, pos)

A = [1, 2, -5, 6, 7, -3, -4]
print(nearest_to_zero(A))
