#include <stdio.h>
#include <algorithm>

using namespace std;

#define M 4
#define N 5

int kadane(int s[])
{
  int maxsofar = 0;
  int maxendinghere = 0;
  for (int i = 0; i < N; i++) {
    maxendinghere = max(maxendinghere + s[i], 0);
    maxsofar = max(maxsofar, maxendinghere);
  }
  return maxsofar;
}

int maxsum(int A[][N])
{
  int i, j, k, sum[N], maxsofar;
  for (i = 0; i < M; i++) {
    for (k = 0; k < N; k++) 
      sum[k] = 0;
    for (j = i; j < M; j++)
      for (k = 0; k < N; k++)
        sum[k] += A[j][k];
      maxsofar = kadane(sum);
  }
  return maxsofar;
}

int main(int argc, const char *argv[]) 
{
  int A[M][N] = {{1, 2, -1, -4, -20},
                 {-8, -3, 4, 2, 1},
                 {3, 8, 10, 1, 3},
                 {-4, -1, 1, 7, -6}
                };
  return 0;
}
