
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int m[30][1000000];
void preprocessing()
{
  // cảm giác vòng for đầu ko cần lắm, nào rảnh bỏ thử check
  for (int j = 0; (1 << j) < n; j++)
  {
    for (int i = 0; i < n; i++)
    {
      m[j][i] = -1; // set tạm min trong đoạn 2 ^ j , 2 ^ j + i = -1
     // cout << "j la: " << j << " i la: "<< i << endl;
    } 
    
  }
  for (int i = 0; i < n; i++) m[0][i] = i; // phần tử min của mảng con 1 phần tử là chính nó
  // vòng for này kiểu min của cục to bằng min của 2 cục nhỏ ghép lại
  // vd đoạn    chỉ số         0 1 2 3 4 5 6 7 
  // giá trị tương ứng         4 5 3 8 3 2 4 1 
  // vậy min a[0, 7] = min(min a[0, 3], min[4, 7])
  // min a[0,3] = min (min a[0, 1], min a[2, 3])
  // min a[0, 1] = min (min a[0], min a[1]) 
  // tính từ a[0, 1] dần lên ta sẽ tính được hết, do đó mới có trò (1 << j == 2 ^ j)
  // còn trò chạy i đoán ko nhầm để care test lẻ
  // ex mảng có 7 phần tử thôi 0 1 2 3 4 5 6
  // lúc này min a[0, 6] = min (min a[0,3] , min a[3, 6]) chấp nhận lặp 3 vẫn okela
  // à bonus thêm bài này set m [j][i] hơi ngược m[i][j] nên nào rảnh code lại
  // và cái trò bài này thì vì lưu giá trị luôn thì nó lưu toạ độ điểm min nhất trong đoạn
  // vd trong ex 1 min a[0, 7] = a[7] chứ nó ko lưu luôn là 1
  // cách này khá hay để sau fusion vs cách lưu 1 giá trị đầu mảng và các giá trị khác tính toán được theo nó
  // vd đề yêu cầu bây h tăng / giảm 1 vài phần tử trong mảng lên 2 3 đơn vị
  // thì ta sẽ chỉ tăng chênh lệch lên 2 3 cho 1 số chỗ or cho phần tử đầu và ko cần dùng for duyệt hết
  // thì như bài này đề mà yêu cầu tăng all phần tử trong mảng lên 1 thì thay vì cực công thay đổi lại giá trị all min các đoạn ta vẫn giữ nguyên nó okela và return a[min[?][?]] là xong
  for (int j = 1; (1 << j) <= n; j++)
  {
    for (int i = 0; i + (1 << j) - 1 < n; i++)
    {
     // cout << "i + (1 << (j - 1)): " << i + (1 << (j - 1)) << "j: " << j << endl;
        if (a[m[j - 1][i]] < a[m[j - 1][i + (1 << (j - 1))]]) m[j][i] = m[j - 1][i];
        else m[j][i] = m[j - 1][i + (1 << (j - 1))];
    }
  }
}
int rmq(int i, int j)
{
  int k = log2(j - i + 1);
  int p2k = (1 << k);
  return min(a[m[k][i]] , a[m[k][j - p2k + 1]]);
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) 
  {
    int temp;
    cin >> temp;
    a[i] = temp;
    m[i][0] = a[i];
  }
  preprocessing();
  int socap;
  cin >> socap;
  int ans = 0;
  for (int i = 0; i < socap; i++)
  {
    int L, R;
    cin >> L >> R;
    ans += rmq(L, R);
  }
  cout << ans;
}