#include <bits/stdc++.h>
using namespace std;


long n;
long a[1000001];
long ans = 0;

void solve()
{
  long i = 2;
  for ( ; i < n; i++ )
  {
    if (a[i] > a[i - 1] && a[i] > a[i + 1])
    {
      i++;
      ans++;
    }
  }
  cout << ans;
}


int main()
{
  scanf("%ld", &n);
  for (long i = 1; i <= n; i++) scanf("%ld", &a[i]);
  solve();
}