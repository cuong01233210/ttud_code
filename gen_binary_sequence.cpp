#include <iostream>
using namespace std;

int n;
int a[20];
void showKq()
{
  for (int i = 1; i <= n; i++)
  {
    cout << a[i];
  }
  cout << "\n";
}
void Try(int k)
{
  for (int i = 0; i < 2; i++)
  {
    a[k] = i;
    if (k == n) showKq();
    else Try(k + 1);
  }
}
int main()
{
  cin >> n;
  Try(1);
}