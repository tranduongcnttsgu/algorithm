#include <iostream>
using namespace std;
struct nodeTree
{
  int data;
  nodeTree *left;
  nodeTree *right;
};
nodeTree *makenode(int data)
{
  nodeTree *tmp = new nodeTree();
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
void add(nodeTree *&a, int data)
{
  if (a == NULL)
  {
    a = makenode(data);
    return;
  }
  if (data > a->data)
    return add(a->right, data);
  else if (data < a->data)
    return add(a->left, data);
}
void print_tree(nodeTree *a)
{
  if (a == NULL)
    return;
  cout << a->data << " ";
  print_tree(a->right);
  print_tree(a->left);
}
bool research(nodeTree *a, int x)
{
  if (a == NULL)
    return false;
  else if (a->data > x)
    return research(a->left, x);
  else if (a->data < x)
    return research(a->right, x);
  else if (a->data == x)
    return true;
}
int count(nodeTree *a)
{
  if (a == NULL)
    return 0;
  return 1 + count(a->right) + count(a->left);
}
void Nodetmp(nodeTree *&a, nodeTree *&b)
{
  if (b->left != NULL)
  {
    Nodetmp(a, b->left);
  }
  else
  {
    a->data = b->data;
    a = b;
    b = b->right;
  }
}
void dele_node(nodeTree *&a, int data)
{
  if (a == NULL)
  {
    return;
  }
  else
  {
    if (data < a->data)
      dele_node(a->left, data);
    else if (data > a->data)
      dele_node(a->right, data);
    else
    {
      nodeTree *temp = a;
      if (a->left == NULL)
        a = a->right;
      else if (a->right == NULL)
        a = a->left;
      else
      {
        Nodetmp(temp, a->right);
      }
      delete temp;
    }
  }
}
int height(nodeTree *a)
{
  if (a == NULL)
    return 0;

  else
  {
    int leftheight = height(a->left);
    int rightheight = height(a->right);
    if (leftheight > rightheight)
      return leftheight + 1;
    else
      return rightheight + 1;
  }
}
int main()
{
  nodeTree *a = NULL;
  while (true)
  {
    cout << "1 add\n";
    cout << "2 search\n";
    cout << "3 print\n";
    cout << "4 delete\n";
    cout << "5. size\n";
    cout << "6 height\n";
    int i;
    cout << "nhap:";
    cin >> i;
    if (i == 1)
    {
      int n;
      cout << "nhap n:";
      cin >> n;
      for (int i = 0; i < n; i++)
      {
        int data;
        cin >> data;
        add(a, data);
      }
    }
    else if (i == 2)
    {
      int x;
      cout << "nhap x:";
      cin >> x;
      if (research(a, x))
        cout << "yes\n";
      else
        cout << "no\n";
    }
    else if (i == 3)
    {

      print_tree(a);
      cout << endl;
    }
    else if (i == 4)
    {
      int data;
      cout << "nhap node can xoa" << endl;
      cin >> data;
      dele_node(a, data);
    }
    else if (i == 5)
    {
      cout << "size:" << count(a) << endl;
    }
    else if (i == 6)
    {
      cout << "chieu cao cua cay:" << height(a) << endl;
    }
  }
}