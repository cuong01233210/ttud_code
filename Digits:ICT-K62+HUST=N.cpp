#include <bits/stdc++.h>
using namespace std;

int N;
int socach = 0;
int a[10]; 
// a[0] = I , a[1] = C, ....
//int I, C, T, K, H, U, S; // from 1 -> 9
int gioihanH;
int assignedValue[11];
int cal()
{
  return a[0] * 100 + a[1] * 10 + a[2] - a[3] * 100 - 62 + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[2];
}

// min 1111 + 111 - 962 = 260
// hàng đơn vị 2 T - 2 -> chẵn


void Try(int k)
{
  for (int i = 1; i <= 9; i++)
  {
    if (assignedValue[i] == false)
    {
      a[k] = i;
      assignedValue[i] = true;
      if (k < 6)
      {
        Try(k + 1);
      }
      else 
      {
        if (cal() == N)
        {
          socach++;
        }
      }
      assignedValue[i] = false;
    }
  }
}



int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= 9; i++) assignedValue[i] = false;
  Try(0);
  cout << socach;
  
  
}
/*Digits:ICT-K62+HUST=N.cpp*/