#include <iostream>
using namespace std;


int n;
int a[10000000];

void showKq()
{
  for (int i = 1; i <= n; i++)
  {
    cout << a[i] << " ";
  }
  cout << "\n";
}
bool check(int i, int k)
{
  if (k == 1) return true;
  else 
  {
    for (int j = 1; j < k; j++)
    {
      if (i == a[j]) return false;
    }
  }
  return true;
}


void Try(int k)
{
  for (int i = 1; i <= n; i++)
  {
    if (check(i, k))
    {
      a[k] = i;
      if (k == n) showKq();
      else Try(k + 1);
    }
  }
}


int main()
{
  cin >> n;
  Try(1);
}