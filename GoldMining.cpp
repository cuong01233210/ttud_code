
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int L1, L2;
int a[N];
int n;

int max_sum = 0;
int S[N];
deque <int> d;
void input ()
{
   ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
  cin >> n >> L1 >> L2;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
}

void Try(int k)
{
  while (!d.empty() && d.front() < k - L2) d.pop_front();
  // dòng này thì để clear những cái không nằm trong đoạn có thể fusion với S[j] hiện tại
        // ex 1 2 3 4 5 6 7 8
        // i = 8 -> chỉ có thể fusion được với 5 hoặc 6 -> cần kick 1 -> 4 bằng dòng lệnh kia 
  int j = k - L1;
  // ex a b 9 6 hiện đang ở 6 -> j = 4 - 2 = 2
        // hiện 6 có thể fusion với 3 hoặc 5
        // không biết nên chọn fusion với 3 hoặc 5 nên mới phải dùng trò này
        // th1: 3 5 9 6
        // S[d.back] = 3 < S[j] = 5 -> kick 1 ra khỏi d
        // -> d = {2} -> S[4] = S[2] + a[4] = 6 + 5 = 11
        // th2: 5 3 9 6
        // không thể kick 1 do 5 > 3 -> d = {1 2}
        //  -> S[4] = S[d.front] + a[4] = 5 + 6 = 11 
  if (j >= 1)
  {
    while (!d.empty() && S[d.back()] < S[j]) d.pop_back();
    d.push_back(j);
  }
  S[k] = a[k] + (d.empty() ? 0: S[d.front()]);
  max_sum = max(max_sum, S[k]);
}

void solve()
{
  for (int k = 1; k <= n; k++)
  {
    Try(k);
  }
  cout << max_sum;
}
int main()
{
  input();
  solve();
  
}















