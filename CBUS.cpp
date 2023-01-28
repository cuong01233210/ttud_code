#include <bits/stdc++.h>
using namespace std;


int n, Q; // n hanh khach, Q ghe ngoi
int c[50][50]; // ma tran khoang cach tu diem i toi j (0 <= i,j <= 2n)
// khách hàng thứ i muốn đi từ điểm i tới điểm i + n -> ma trận khoảng cách mới có trò i from 0 -> 2n
// 0 là trạm xe bus, các điểm i từ 1 -> 2n là điểm trên lộ trình
// ngoại trừ điểm 0, các điểm khác được thăm tối đa 1 lần 
int visited[50];
int so_hanh_khach_tren_xe = 0;
int quang_duong_min = 1e9;
int quang_duong_da_di = 0;
int lotrinh[50]; // mảng chứa lộ trình khách đi
int dm = 1e9;
bool check(int i, int k)
{
  if (visited[i] == 1) return false;
  if (i <= n)
  { // nếu điểm tiếp theo là điểm đón khách
    // ở điểm đón khách mà xe đã full slot thì skip
    if (so_hanh_khach_tren_xe >= Q) return false;
  }
  else
  { // nếu điểm tiếp theo là điểm trả khách
    // ở điểm trả khách mà khách còn chưa đón thì cũng skip
    if (visited[i - n] == 0) return false;
  }
  return true;
}
void solution()
{
  
  // tìm ra quãng đường min mới nhất
  if (quang_duong_min  > quang_duong_da_di + c[lotrinh[2 * n]][lotrinh[0]])
  {
    // lấy quãng đường đi được từ 0 -> trạm trả khách cuối 
    // + quãng đường từ trạm trả khách cuối về 0
    quang_duong_min = quang_duong_da_di + c[lotrinh[2 * n]][lotrinh[0]];
  }
}
void Try(int k)
{
  for (int i = 1; i <= 2 * n; i++)
  {
    if (check(i, k) == true)
    {
      lotrinh[k] = i;
      visited[i] = 1; // đánh dấu đã duyệt
      quang_duong_da_di += c[lotrinh[k - 1]][lotrinh[k]]; // quãng đường đi được += quãng đường nối từ điểm trước đó tới điểm đang target
      if (i <= n) // nếu đang ở trạm đón khách thì tăng số hành khách lên 1
      {
        so_hanh_khach_tren_xe++;
      }
      else // nếu đang ở trạm trả khách thì giảm số khách đi 1
      {
        so_hanh_khach_tren_xe--;
      }
      if (k == 2 * n) // nếu duyệt hết các trạm rồi thì có kết quả thôi
      {
        solution();
      }
      else 
      {
        if (quang_duong_da_di + (2 * n - k - 1) * dm  < quang_duong_min)
        {
          // dùng kiểu đk trong if kia để cắt nhánh vì quãng đường tiếp theo tối thiểu cần đi
          // = quãng đường hiện tại + số trạm tối thiểu cần đi tiếp * độ dài tối thiểu mỗi bước đi là dm
          Try(k + 1);  
        }
      }
      // phục hồi trạng thái
      if (i <= n) 
      {
        so_hanh_khach_tren_xe--;
      }
      else
      {
        so_hanh_khach_tren_xe++;
      }
      quang_duong_da_di -= c[lotrinh[k - 1]][lotrinh[k]];
      visited[i] = 0;
    }
  }
}

int main()
{
  cin >> n >> Q;
  lotrinh[0] = 0;
  for (int i = 0; i <= 2 * n; i++ )
  {
    for (int j = 0; j <= 2 * n; j++)
    {
      int temp;
      cin >> temp;
      c[i][j] = temp;
      visited[i] = 0;
      if (dm > temp && i != j) dm = temp; // tìm bước đi tối thiểu mỗi lần xe phải đi
    }
  }
  
  Try(1);
  cout << quang_duong_min;
  
}

/*
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0

với test case này tìm được route min trước cộng tram cuối là 
0 3 1 4 2 6 5 -> s = 22
tuy bé hơn route trước từ trạm cuối về 0 của
0 3 2 6 1 5 4 -> s = 18
nma do quãng đường từ trạm cuối của c[5][0] = 3, c[4][0] = 9
-> route ngắn nhất phải là 0 3 1 4 2 6 5 0
*/