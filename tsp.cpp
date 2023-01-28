#include <bits/stdc++.h>
using namespace std;
int n;

int F[21][1000001];
int c[21][21];

// 4 3 2 1 0
// 1 0 0 0 1

bool contains(unsigned int S, int x)
{
  if (S && (1 << x)) return true;
  else return false;
}
unsigned int removeElement(unsigned int S, int x)
{
  return S & (~(1 << x)); // note: toan tu & != toan tu &&
}
unsigned int addElement (unsigned int S, int x)
{
  return S | (1 << x);
}
int TSP(int i, int S)
{
  if (S == 0)
  {
    //cout << "da duyet toi S== 0 tai i: "<< i << endl; 
    F[i][S] = c[i][0];
    return F[i][S];
  }
  if (F[i][S]< 0)
  {
    
    F[i][S] = 1e9; 
    for (int j = 0; j < n; j++)
    {
      if (contains(S, j))
      {
        unsigned int Sj = removeElement(S, j);
        //cout << "F[i][S] duyet " << " i: " << i << " Sj: " << Sj << endl;
        int tsp = TSP(j, Sj);
        int Tj = tsp + c[i][j];
       // cout << "Tj: " << Tj << " tsp: " << tsp << " c[i][j]: " << c[i][j] << endl;
        if (F[i][S] > Tj)
        {
         // cout << "i: " << i << " S: " << S << " F[i][S]: " << F[i][S];
          F[i][S] = Tj;
        }
      }
    }
  }
  return F[i][S];
}



int main()
{
  ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
  cin >> n;
  unsigned int S = (1 << n) - 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> c[i][j];
      //F[i][j] = -1;
    }
  }
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j <= 1000000; j++) F[i][j] = -1;
  }
 // cout << contains(S, 0) << endl;
  int ans = TSP(0, (1 << n) - 1);
  cout << ans;
  return 0;

}
/*
4 
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
*/
/*
13
0 68 35 1 70 25 79 59 63 65 6 46 82
28 0 92 96 43 28 37 92 5 3 54 93 83
22 17 0 96 48 27 72 39 70 13 68 100 36
95 4 12 0 34 74 65 42 12 54 69 48 45
63 58 38 60 0 42 30 79 17 36 91 43 89
7 41 43 65 49 0 6 91 30 71 51 7 2
94 49 30 24 85 55 0 41 67 77 32 9 45
40 27 24 38 39 19 83 0 42 34 16 40 59
5 31 78 7 74 87 22 46 0 73 71 30 78
74 98 13 87 91 62 37 56 68 0 75 32 53
51 51 42 25 67 31 8 92 8 38 0 88 54
84 46 10 10 59 22 89 23 47 7 31 0 69
1 92 63 56 11 60 25 38 49 84 96 42 0
*/