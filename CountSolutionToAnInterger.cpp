#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> x;
//vector <int> X_max;
vector <int> t;
int n, M;
int f = 0;
int ans = 0;
void solution()
{
  /*
  for (int i = 1; i <= n; i++) 
  {
    cout << x[i] << " ";
  }
  */
  //cout << endl;
  ans++;
}
void Try(int k)
{
  for (int v = 1; v <= (M - f - (t[n] - t[k]))/ a[k]; v++)
  {
    x[k] = v;
    f = f + a[k] * x[k];
   // cout << "k: " << k << " v: "<< v << " f: "<< f << endl;
    if (k < n) Try(k + 1);
    else 
    {
      if (f == M) solution();
    }
    f = f - a[k] * x[k];
  }
}
int main()
{
  cin >> n >> M;
  int sum_ak;
  a.push_back(0);
  x.push_back(0);
  t.push_back(0);
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    a.push_back(temp);
    x.push_back(0);
    sum_ak += temp;
    t.push_back(sum_ak);
    //X_max.push_back(M / temp);
  }
  Try(1);
  cout << ans;
}