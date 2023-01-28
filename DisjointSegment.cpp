#include <bits/stdc++.h>
using namespace std;
vector <int> a;
vector<int> b;
int n;
pair < vector <int>, vector <int> > L;
void Greedy3()
{
  int res = 0;
  int last = -1;
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    if (L.first[i] > last)
    {
      //cout << L.first[i] << " " << L.second[i] << " " << last << endl;
      res++;
      last = L.second[i];
      
    }
  }
  cout << res << endl;
}

void selectionSort()
{
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (b[j] < b[min]) min = j;
    }
    // swap b[i], b[min]
    temp = b[i];
    b[i] = b[min];
    b[min] = temp;
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
  }
}
int main()
{
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    a.push_back(temp);
    scanf("%d", &temp);
    b.push_back(temp);
  }
  selectionSort();
 // sort(a.begin(), a.end());
  L = make_pair(a, b);
  Greedy3();
  
  /*
  for (int i = 0; i < n; i++)
  {
    cout << L.first[i] << " " << L.second[i]  << endl;
  }
  */
  
}
/*
6
0 10
3 7
6 14
9 11
12 15
17 19
*/

/*
0 7
3 10
6 11
9 14
12 15
17 19
*/