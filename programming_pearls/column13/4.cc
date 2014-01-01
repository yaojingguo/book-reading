#include <stdio.h>

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
    void insert(int t) {}
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
      int i = t / (1 + maxval/bins);  // CHECK !
    }
    void report(int *v)
    { 
      int j = 0;
      for (int i = 0; i < bins; i++)
        for (node *p = bin[i]; p != sentinel; p = p->next)
          v[j++] = p->val;
    }
};

int main(int argc, const char *argv[]) 
{
  return 0;
}
