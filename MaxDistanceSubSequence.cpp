#include <bits/stdc++.h>
using namespace std;
int T, N, C;
int a[100001];
//int b[100001];

bool check(int distance)
{
  int sl = 1;
  int i = 1, j = 2;
  while(i < N)
  {
    while (j <= N && a[j] - a[i] < distance) ++j;
    if (j <= N) sl++;
    if (sl >= C) return true; // co the lay duoc c phan tu
    i = j;
    j++;
  }
  return false;
}

int MaxDistance()
{
  int l = 0, r = a[N] - a[1];
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1;
    else r = mid - 1;
  }
  return r;
}
int main()
{
  //ios_base :: sync_with_stdio(0);
  //cin.tie(0);
  //cout.tie(0);
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d%d", &N, &C);
    for (int j = 1; j <= N; j++)
    {
      scanf("%d", &a[j]);
      //b[i] = a[i];
    }
    sort(a, a + N);
    cout << MaxDistance() << endl;
   // solve ((a[1] + a[N]) / 2);
  }

  
}
/*
1 ​
5 3 ​
1 ​
2 ​
8 ​
4 ​
9
​*/