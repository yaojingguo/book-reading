#include <stdio.h>

struct node {
  int val;
  struct node* next;
  struct node* fold;
  node(int val_, node* next_ = NULL, node* fold_ = NULL) :
    val(val_), next(next_), fold(fold_) {}
};

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

void info(node* h)
{
  while (h != NULL) {
    printf("%d ", h->val);
    h = h->next;
  }
  printf("\n");
}

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

void test_build()
{
  node* h = build();
  info(h);
}

void test_path()
{
  path(6); printf("\n");
  path(5); printf("\n");
  path(11); printf("\n");
}

int main(int argc, const char *argv[]) 
{
  test_path();
  return 0;
}
