#include <bits/stdc++.h>
using namespace std;
// dùng thuật toán quy hoạch động ms ăn được
long long a[1001][1001];

long long C(int k, int n)
{
 
  for (int i = 2; i <= n; i++)
  {
    for (int j = 2; j <= i - 1; j++)
    {
      a[j][i] = (a[j - 1][i - 1] + a[j][i - 1]) % 1000000007;
    }
  }
  return a[k][n];
 
}



int main()
{
  int n, k;
  cin >> k >> n;
  for (int i = 0; i <= n; i++)
  {
    //  if (k == 0 || k == n) a[k][n] = 1;
    a[i][i] = 1; // k = n case 
    a[0][i] = 1; // k = 0 case
  }
  for (int i = 2; i <= n; i++)
  {
    // if (k == 1) a[k][n] = n;
    a[1][i] = i; // k = 1 case
  }
  cout << C(k, n) % 1000000007 ;
}