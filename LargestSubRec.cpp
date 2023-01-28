#include <bits/stdc++.h>
using namespace std;

#define N 1001
int A[N][N];
int n, m;

// cách làm: mượn tạm cách tìm s max của bài đồ thị cột
// ex: có biểu đồ cột với các cột có độ cao 1 2 3 4 5 3 1 1 
// thì ta tìm được s min là 3 * 4 = 12
// thì ở bài này ta sẽ tìm được s max các tầng rồi so ra s max nhất
// ex: 
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0

// Now If the current row is not the first row then update the row as follows, 
// if matrix[i][j] is not zero then matrix[i][j] = matrix[i-1][j] + matrix[i][j].
// Step 1: 0 1 1 0  maximum area  = 2
// Step 2:
// row 1  1 2 2 1  area = 4, maximum area becomes 4
// row 2  2 3 3 2  area = 8, maximum area becomes 8
// row 3  3 4 0 0  area = 6, maximum area remains 8

// cách giải bài tìm diện tích lớn nhất tạo thành của biểu đồ cột
// Create an empty stack.
// Start from the first bar, and do the following for every bar hist[i] where ‘i‘ varies from 0 to n-1
// - If the stack is empty or hist[i] is higher than the bar at top of the stack, then push ‘i‘ to stack. 
// - If this bar is smaller than the top of the stack,
// then keep removing the top of the stack while the top of the stack is greater. 
// - Let the removed bar be hist[tp]. 
// Calculate the area of the rectangle with hist[tp] as the smallest bar. 
// - For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i‘ (current index).
// If the stack is not empty, 
// then one by one remove all bars from the stack and do step (2.2 and 2.3) for every removed bar
int getMaxArea(int hist[], int n)
{
  stack <int> s;
  int max_area = 0 ;
  int tp; // to store top of stack
  int area_with_top; // To store area with top bar
  int i = 0;
  while (i < n)
  {
    if(s.empty() || hist[s.top()] < hist[i])
    {
      s.push(i);
      i++;
    }
    else
    {
      tp = s.top();
      s.pop();
      area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
      if (max_area < area_with_top) max_area = area_with_top;
    }
  }
  while (s.empty() == false)
  {
    tp = s.top();
    s.pop();
    area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
    if (max_area < area_with_top) max_area = area_with_top;
  }
  return max_area;
}

int maxRectangle()
{
    // Calculate area for first row and initialize it as
    // result
    int result = getMaxArea(A[0], m);
 
    // iterate over row to find maximum rectangular area
    // considering each row as histogram
    for (int i = 1; i < n; i++) {
 
        for (int j = 0; j < m; j++)
 
            // if A[i][j] is 1 then add A[i -1][j]
            if (A[i][j])
                A[i][j] += A[i - 1][j];
 
        // Update result if area with current row (as last
        // row) of rectangle) is more
        result = max(result, getMaxArea(A[i], m));
    }
 
    return result;
}





int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> A[i][j];
    }
  }
  cout << maxRectangle();
}