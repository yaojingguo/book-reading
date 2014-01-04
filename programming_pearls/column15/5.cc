#include <iostream>
#include <map>
#include <string>
using namespace std;

struct node {
  string s;
  struct node* next;
};

int main()
{ 
  map<string, int> M;
  map<string, int>::iterator j;
  string s;
  while (cin >> s)
    M[s]++;

  map<int, node*> T;
  node** p;
  int cnt;
  for (j = M.begin(); j != M.end(); ++j) {
    s = j->first;
    cnt = j->second;
    for (p = &T[cnt]; (*p) != NULL; p = &((*p)->next))
      ;
    (*p) = new node();
    (*p)->s = s;
    (*p)->next = NULL;
  }

  map<int, node*>::reverse_iterator k;
  node* q;
  for (k = T.rbegin(); k != T.rend(); ++k) {
    cnt = k->first;
    for (q = k->second; q != NULL; q = q->next)
      cout << q->s << " " << cnt << endl;
  }
  return 0;
}
