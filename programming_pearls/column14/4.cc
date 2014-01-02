#include <stdio.h>

// Build Huffman code from sorted x in O(n) time.
// Aggregate analysis: If j-loop for one i-iteration is O(k), the following k 
// i-loop iterations are all O(1). The total cost for these k+1 iterations is 
// O(k) + kO(1).  So the amortized cost of one iteration in these k+1 iteration 
// is (O(k) + kO(1)) / k = O(1).
void huffman(int x[], int n)
{
  int i, j, s;
  for (i = 0; i < n - 1; i++) {
    s = x[i] + x[i + 1];
    printf("%d\n", s);
    for (j = i + 2; i < n && s > x[j]; j++)
      x[j - 1] = x[j];
    x[j - 1] = s;
  }
}

int main(int argc, const char *argv[]) 
{
  int x[] = {4, 5, 7, 11, 15};
  huffman(x, 5);
  return 0;
}
