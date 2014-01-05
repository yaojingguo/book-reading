#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int bigrand()
{
  return RAND_MAX * rand() + rand();
}

int randint(int l, int u)
{
  int mod = u - l + 1;
  int r = bigrand() % mod;
  if (r < 0) r += mod;
  return l + r;
}

int main(int argc, const char *argv[]) 
{
  vector<string> V;
  string t;
  while (cin >> t)
    V.push_back(t);

  srand(getpid());
  int u = V.size() - 1;
  for (int max = 10; max > 0; max--)
    cout << V[randint(0, u)] << " ";
  cout << endl;

  return 0;
}
