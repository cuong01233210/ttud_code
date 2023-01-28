#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > A;
vector <vector <int> > bookmark;
queue <int> x;
queue <int> y;
int n, m, r, c;
vector <vector <int> > cnt_step;


void duyet()
{
  

 
  while(!x.empty() )
  {
        int o[] = {0, 1, 0, -1};
        int p[] = {1,0, -1 ,0};
       int cur_row = x.front();
       int cur_col = y.front();
        x.pop();
        y.pop();
        if (cur_row == 1 || cur_row == n || cur_col == 1 || cur_col == m)
        {
          cout << cnt_step[cur_row][cur_col] + 1;
          return;
        }
        for (int d = 0; d < 4; d++)
        {
            if( cur_row + o[d] > 0 && cur_row+o[d] < A.size() &&  cur_col+p[d] > 0 && cur_col+p[d] < A[1].size() && A[cur_row+o[d]][cur_col+p[d]] == 0 && bookmark[cur_row+o[d]][cur_col+p[d]] == 0 )
            {
                bookmark[cur_row+o[d]][cur_col+p[d]] = 1;
                x.push(cur_row+o[d]);
                y.push(cur_col+p[d]);
               
                 int t = cnt_step[cur_row][cur_col] + 1;
                cnt_step[cur_row+o[d]][cur_col+p[d]] = t;
            }
        }
       
        
        
  }
   cout << "-1";
 
  
}




int main()
{
  cin >> n >> m >> r >> c;
  for (int i = 0; i <= n; i++)
  {
      vector <int> line;
      vector <int> bookmarkline;
      vector <int> cnt_line;
      cnt_line.push_back(0);
      line.push_back(0);
      bookmarkline.push_back(0);
      if (i == 0)
      {
        for (int j = 0; j < m; j++) 
        {
          line.push_back(0);
          bookmarkline.push_back(0);
          cnt_line.push_back(0);
        }
        
      }
      else 
      {
          for (int j = 0; j < m; j++)
        {
          int temp;
          cin >> temp;
          line.push_back(temp);
          bookmarkline.push_back(0);
          cnt_line.push_back(0);
        }
      }
    
      A.push_back(line);
      bookmark.push_back(bookmarkline);
      cnt_step.push_back(cnt_line);
  }
  cnt_step[r][c] = 0;
  bookmark[r][c] = 1; // da duyet qua
  x.push(r);
  y.push(c);
  duyet();
  cout << "\n";

  
}


/*
 8 12 5 6
 1 1 0 0 0 0 1 0 0 0 0 1
 1 0 0 0 1 1 0 1 0 0 1 1
 0 0 1 0 0 0 0 0 0 0 0 0
 1 0 0 0 0 0 1 0 0 1 0 1
 1 0 0 1 0 0 0 0 0 1 0 0
 1 0 1 0 1 0 0 0 1 0 1 0
 0 0 0 0 1 0 1 0 0 0 0 0
 1 0 1 1 0 1 1 1 0 1 0 1
 */
/*
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  */
 /*
 for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << bookmark[i][j] << " ";
    }
    cout << endl;
  }
  */
 /*
 3 3 2 2
 1 1 1
 1 0 1
 1 1 1 
 */
/*
4 4 3 3
1 0 1 1 
1 0 1 1
1 0 0 1
1 1 0 1
*/

/*
5 5 3 2
1 1 1 0 0
1 0 0 0 1
1 0 0 0 1
1 1 0 1 1 
1 1 0 1 1 
*/