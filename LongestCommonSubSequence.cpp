#include <bits/stdc++.h>
using namespace std;

int n, m;
int X[10001];
int Y[10001];

int L[10001][10001];


void init()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &X[i]);
    L[i][0] = 0;
  }
  for (int j = 1; j <= m; j++)
  {
    scanf("%d", &Y[j]);
    L[0][j] = 0;
  }
}
void solveBottomUp()
{
  //for (int i = 0; i <= n; i++) L[i][0] = 0;
  //for (int j = 0; j <= m; j++) L[0][j] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (X[i] == Y[j]) L[i][j] = L[i - 1][j - 1] + 1;
      else
      {
        if (L[i - 1][j] > L[i][j - 1]) L[i][j] = L[i - 1][j];
        else L[i][j] = L[i][j - 1];
      }
    }
  }
  cout << L[n][m];
}







int main()
{
  init();
  //for (int i = 0; i < n; i++) cout << X[i] << " ";
  //for (int j = 0; j < m; j++) cout << Y[j] << " ";
  solveBottomUp();
}
/*
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
*/