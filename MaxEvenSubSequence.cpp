#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 +1;
int S0[N];
int S1[N];

int n;
int a[N];

int tt0[N];
int tt1[N];

void input()
{
  ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    tt0[i] = 0;
    tt1[i] = 0;
  }
}

void solve()
{
  if(a[1]%2==0){S0[1] = a[1];tt0[1] = true;tt1[1] = false;}else {
        S1[1] = a[1];tt1[1] = true;tt0[1] = false;
    }
  for (int i = 2; i <= n; i++)
  {
    if (a[i] % 2 == 0) // nội tại chẵn: duy trì tính chất chẵn -> chẵn, lẻ -> lẻ
    {
      tt0[i] = 1;
      if (tt0[i - 1] == 0) 
      {
        S0[i] = a[i];
      }
      else 
      {
        if (S0[i - 1] + a[i] > a[i])
        {
          S0[i] = S0[i - 1] + a[i];
        }
        else
        {
          S0[i] = a[i];
        }
      }
      if (tt1[i - 1] == 1)
      {
        S1[i] = S1[i - 1] + a[i];
        tt1[i] = 1;
      }
    }
    else // nội tại đảo tính chất chẵn -> lẻ, lẻ -> chẵn
    {
      tt1[i] = 1;
      int max_temp = a[i];
      if (tt0[i - 1] == 0)
      {
        S1[i] = a[i];
      }
      else
      {
        if (S0[i - 1] + max_temp > max_temp)
        {
          S1[i] = S0[i - 1] + max_temp;
        }
        else 
        {
          S1[i] = max_temp;
        }
      }
      if (tt1[i - 1] == 1)
      {
        tt0[i] = 1;
        S0[i] = S1[i - 1] + a[i];
      }
    }
  }
    long long ans = -1e18;
for (int i=1;i<=n;i++){
        if(tt0[i] && ans <S0[i]) ans=S0[i];
    }
    cout <<ans <<endl;
}




int main()
{
  
  input();
  if (n == 1 && a[1] % 2 != 0)
  {
    cout << "NOT_FOUND";
  }
  else
  {
   
    solve();
   
  }
}
