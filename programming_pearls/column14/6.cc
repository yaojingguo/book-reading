#include <stdio.h>
#include <assert.h>

struct node {
  int val;
  struct node* next;
  struct node* fold;
  node(int val_, node* next_ = NULL, node* fold_ = NULL) :
    val(val_), next(next_), fold(fold_) {}
};

bool even(int n)
{
  return (n & 1) == 0;
}

void path(int n)
{
  if (n == 0) 
    printf("start at 0");
  else if (even(n)) {
    path(n / 2);
    printf(", double to %d", n);
  } else {
    path(n - 1);
    printf(", increment to %d", n);
  }
}

int log(unsigned pow)
{
  assert(pow > 0);
  int i = 0;
  while (pow > 1) {
    pow >>= 1;
    i++;
  }
  return i;
}

node* build()
{
  node* node7 = new node(7);
  node* node6 = new node(6, node7);
  node* node5 = new node(5, node6);
  node* node4 = new node(4, node5);
  node* node3 = new node(3, node4, node6);
  node* node2 = new node(2, node3, node4);
  node* node1 = new node(1, node2, node2);
  return node1;
}

void access(unsigned n)
{
  unsigned l, mask, i;
  i = 1;
  l = log(n);
  printf("start at 1");
  if (l == 0)
    goto ret;
  mask = 1 << (l - 1);
  while (mask > 0) {
    printf(", double to %d", i = 2 * i);
    if (n & mask) {
      printf(", increment to %d", ++i);
    } 
    mask >>= 1;
  }
ret:
  printf("\n");
}

void info(node* h)
{
  while (h != NULL) {
    printf("%d ", h->val);
    h = h->next;
  }
  printf("\n");
}

void test_info()
{
  node* h = build();
  info(h);
  assert(log(8) == 3);
  assert(log(9) == 3);
  assert(log(15) == 3);
  assert(log(16) == 4);
}

void test_path()
{
  path(6); printf("\n");
  path(5); printf("\n");
  path(11); printf("\n");
}

void test_access()
{
  access(6);
  access(5);
  access(11);
}

int main(int argc, const char *argv[]) 
{
  // test_path();
  test_access();
  return 0;
}
