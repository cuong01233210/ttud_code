#include <bits/stdc++.h>
using namespace std;

int m, n;
// m: so giao vien, n so mon hoc
vector <vector <int> > a; // mang chua cac mon ma giao vien thu i co the day
int mauthuan[100][2]; // mang chua cac cap mon mau thuan voi nhau
int min_cac_solution = 1e9;
vector <int> load; // so mon duoc phan cong giang day cho tungf giao vien
int x[31]; // mark giao vien i day mon i 
int z; // so cap mau thuan
vector <vector< int> > daday;
bool check(int i, int t)
{
  if (a[i][t] == 1)
  {
    for (int j = 0; j < z; j++)
    {
      int temp1 = mauthuan[j][0];
      int temp2 = mauthuan[j][1];
      if (temp2 == i && daday[temp1][t] == 1)
      {
        return false;
      }
      if (temp1 == i && daday[temp2][t] == 1)
      {
        return false;
      }
    }
    return true;
  }
  else 
  {
    return false;
  }
}
void solution()
{
 // for (int i = 1; i <= m; i++) cout << load[i] << " ";
 // cout << endl;
  int max_e = *max_element(load.begin(), load.end());
  if (min_cac_solution > max_e)
  {
    min_cac_solution = max_e;
  }
}
void Try(int i)
{
  for (int t = 1; t <= m; t++) // t = teacher
  {
    if (check(i, t) == true)
    {
      load[t] += 1;
      daday[i][t] = 1;
      if (i == n)
      {
       solution();  
      }
      else
      {
        if (load[t] < min_cac_solution)
        {
          Try(i + 1);
        }
      }
      load[t] -= 1;
      daday[i][t] = 0;
      
    }
    
  }
  
}




int main()
{

  cin >> m >> n;
  vector <int> zero;
  for (int i = 0; i < m + 1; i++) 
  {
    zero.push_back(0);
    load.push_back(0);
  } 
  for (int t = 0; t <= 31; t++)
  {
    a.push_back(zero);
    daday.push_back(zero);
  }
  for (int t = 1; t < m + 1; t++)
  {
    int k;
    cin >> k;
    //cout << k << " ";
    for (int i = 1; i <= k; i++)
    {
      int temp;
      cin >> temp;
      a[temp][t] = 1;
    }
    
  }
  cout << endl;
  
  cin >> z;
  //cout << "z: " << z << endl;
  for (int i = 0; i < z; i++)
  {
    int temp1;
    cin >> temp1;
    mauthuan[i][0] = temp1;
    int temp2;
   cin >> temp2;
    mauthuan[i][1] = temp2;
  }
  Try(1);
  
  cout <<  min_cac_solution;
 // cout << 1;

  
}
/*
  for (int t = 1; t <= m; t++)
  {
    for (int i = 1; i <= n; i++)
    {
      cout << a[i][t] << " ";
    }
    cout << endl;
  }
  */
  
  /*
  for (int i = 0; i < z; i++)
  {
    cout << mauthuan[i][0] << " " << mauthuan[i][1] << endl;
  }
  */
  
/*
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
5
1 2
1 3
1 5
2 4
2 5
*/
/*
bang hien thi a[subject][teacher] do chua trong vector nen hoi nguoc
1 0 1 0 1 0 0 0 0 1 0 1 
0 0 1 1 0 0 0 1 1 0 0 1 
1 1 1 1 0 0 1 0 1 0 0 0 
1 1 1 0 1 1 0 0 0 1 1 0 
*/