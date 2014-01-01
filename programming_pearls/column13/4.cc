#include <stdio.h>
#include <assert.h>

class IntSetList {
  private:
    int n;
    struct node {
      int val;
      node *next;
      node(int i, node *p) { val = i; next = p; }
    };
    node *head, *sentinel;
  public:
    IntSetList(int maxelements, int maxval)
    { 
      sentinel = head = new node(maxval, 0);
      n = 0;
    }
    int size() { return n; }
    void insert(int t) 
    {
      node* p = head;
      node* q = NULL;
      while (t > p->val) {
        q = p;
        p = p->next;
      }
      node* r = new node(t, p);
      if (q == NULL) {
        head = r;
      } else {
        q->next = r;
      }
      n++;
    }
    void report(int *v)
    {
      int j = 0;
      for (node *p = head; p != sentinel; p = p->next)
        v[j++] = p->val;
    }
};

class IntSetBST {
  private:
    int n, *v, vn;
    struct node {
      int val;
      node *left, *right;
      node(int v) { val = v; left = right = 0; }
    };
    node *root;
    void traverse(node *p)
    {
      if (p == 0)
        return;
      traverse(p->left);
      v[vn++] = p->val;
      traverse(p->right);
    }
  public:
    IntSetBST(int maxelements, int maxval) { root = 0; n = 0; }
    int size() { return n; }
    void insert(int t) { }
    void report(int *x) { v = x; vn = 0; traverse(root); }
};

class IntSetBins {
  private:
    int n, bins, maxval;
    struct node {
      int val;
      node *next;
      node(int v, node *p) { val = v; next = p; }
    };
    node **bin, *sentinel;
  public:
    IntSetBins(int maxelements, int pmaxval)
    { 
      bins = maxelements;
      maxval = pmaxval;
      bin = new node*[bins];
      sentinel = new node(maxval, 0);
      for (int i = 0; i < bins; i++)
        bin[i] = sentinel;
      n = 0;
    }
    int size() { return n; }
    void insert(int t)
    { 
      int i = t / (1 + maxval/bins); 
      node* p = bin[i];
      node* q = NULL;
      while (t > p->val) {
        q = p;
        p = p->next;
      }
      node* r = new node(t, p);
      if (q == NULL) {
        bin[i] = r;
      } else {
        q->next = r;
      }
      n++;
    }
    void report(int *v)
    { 
      int j = 0;
      for (int i = 0; i < bins; i++)
        for (node *p = bin[i]; p != sentinel; p = p->next)
          v[j++] = p->val;
    }
};

void info(int x[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", x[i]);
  printf("\n");
}

void test_list()
{
  IntSetList set(3, 10);
  set.insert(0);
  set.insert(7);
  assert(set.size() == 2);
  int* v = new int[set.size()];
  set.report(v);
  info(v, set.size());
  delete [] v;
}

void test_bins()
{
  IntSetBins set(10, 100);
  set.insert(0);
  set.insert(7);
  set.insert(27);
  set.insert(80);
  assert(set.size() == 4);
  int* v = new int[set.size()];
  set.report(v);
  info(v, set.size());
  delete [] v;
}

void test_bst()
{
}

int main(int argc, const char *argv[]) 
{
  test_list();
  test_bins();
  test_bst();
  return 0;
}
