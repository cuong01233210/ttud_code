#include <iostream>
using namespace std;

int n;
int a[20];
void showKq()
{
  for (int i = 1; i <= n; i++)
  {
    cout << a[i] ;
  }
  cout << "\n";
}
bool check(int i, int k)
{
    if (k == 1) return true;
    if (a[k - 1] == 1 && i == 1) return false;
    return true;
}
void Try(int k)
{
  for (int i = 0; i < 2; i++)
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