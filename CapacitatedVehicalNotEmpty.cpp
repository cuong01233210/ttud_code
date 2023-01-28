
#include <bits/stdc++.h>
using namespace std;

#define N 50 // số khách hàng tối đa mà code này làm được
int c[N][N]; // ma trận chứa khoảng cách giữa các quãng đường
// c[i][j]: quãng đường đi từ i tới j , note c[i][j] != c[j][]
int n, K, Q; // n là số khách hàng cần giao, K là số xe tải cần cấp -> K là số route cần làm
// Q là tải trọng tối đa mà 1 xe chở được 
int d[N]; // mảng d[N] chứa khối lượng hàng mà khách thứ d[i] yêu cầu d = demand
int visited[N]; // mảng check xem đã gửi hàng cho khách này chưa
int f; // f là độ dài quãng đường tích luỹ của K route
int f_min; // là lộ trình ngắn nhất cần tìm, là min của các f tìm được
int load[N]; // load[k] : tổng lượng hàng trên route thứ k
int nbSegments; // số chặng trên K route = n + K
// ex có 2 route
// route 1: 0 -> 1 -> 4 -> 5 -> 0
// route 2: 0 -> 2 -> 3 -> 0
// cứ 1 -> thì nbSegment += 1 -> nbSegments = 7
// có 2 route -> K = 2, n = 5 (5 khách hàng 1 2 3 4 5) (0 là kho)
// -> khi ta có biểu thức nbSegments = n + K tức là ta đã duyệt hết tất cả các khách hàng
int x[N]; // x[i]: điểm tiếp theo của khách hàng i trên lộ trình
int y[N]; // y[k]: điểm khách hàng đầu tiên của route k
int can_duoi; // sử dụng phương pháp nhánh và cận
void input()
{
  cin >> n >> K >> Q;
  can_duoi = 1e9;
  for (int i = 1; i <= n; i++) cin >> d[i];
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      cin >> c[i][j];
      if (i != j && c[i][j] < can_duoi) can_duoi = c[i][j];
      // với điều này ta sure kèo f_min >= can_duoi * n;
    }
  }
}

bool checkY(int v, int k)
{
  if (load[k] + d[v] > Q) return false;
  else return true;
}

bool checkX(int v, int i, int k)
{
  if (v == 0) return true; // về kho auto được
  if (load[k] + d[v] > Q) return false;
  if (visited[v] == true) return false;
  return true;
}
void Solution()
{
  if (f < f_min)
  {
    f_min = f;
  }
}

void TryX(int i, int k)
{
  // thử giá trị cho x[i] - điểm tiếp theo của i trên route[k]
  for (int v = 0; v <= n; v++)
  {
    if (checkX(v, i, k))
    {
      x[i] = v; // điểm đến tiếp theo của x[i] là v
      // ex trên route 1: 0 -> 2 -> 5 -> 7 ->0
      // thì x[2] = 5, x[5] = 7
      visited[v] = true;
      load[k] += d[v]; // tăng tổng trọng lượng sản phẩm chuyển lên tương ứng
      f += c[i][v]; // quãng đường tích luỹ được trên hành trình ship hàng tăng lên tương ứng
      nbSegments += 1;

      if (v == 0) // nếu đã tới giới hạn và phải về kho
      {
        if (k == K) // route cuối cùng cũng đã hoàn thành
        {
          if (nbSegments == n + K) 
          {
            // nếu đã ở route cuối cùng <-> đã chuyển xong cho all khách hàng
            // có trường hợp hoàn thành route cuối rồi tuy nhiên 1 số khách hàng vẫn chưa được giao hàng 
            // kiểu số xe không đủ or có khách nào lầy quá yêu hàng lượng hàng quá tải xe -> tịt
            // nma t đoán không có test case nào vậy đâu nếu ko tịt à
            Solution();
          }
        } 
        else // nếu chưa hoàn thành route cuối thì làm route tiếp
        {
          if (f + can_duoi * (n + K - nbSegments) < f_min)
            // tính cận dưới ở time này bằng quãng đường đã đi được + giá trị nhỏ nhất mà 1 bước có thể đi được * số bước còn lại có thể đi
            // nếu cận dưới mới (tức là kết quả min nhất mà lộ trình này đi được > kết quả trước đó ta tìm được)
            // -> ta không cần làm nữa vì mất công
            // ngược lại thì ta vẫn cần check tiếp 
            // à bonus thêm số bước còn lại có thể đi là n + K - nbSegments (có giải thích ở phần code trên r)
            TryX(y[k + 1], k + 1);
        }
          
      }
      else // nếu trong route đang xét xe vẫn chưa về kho và có thể chuyển hàng tiếp được 
        {
          if(f + can_duoi * (n + K - nbSegments) < f_min)
          TryX(v, k);
        }
        // phục hồi trạng thái
        visited[v] = false;
        nbSegments -= 1;
        load[k] -= d[v];
        f -= c[i][v];
    }
  }
}




void TryY(int k)
{
  for (int v = y[k - 1] + 1; v <= n - K + k; v++)
  {
    // để tránh trường hợp lặp nên mới dùng v như này
    // ex 
    // cách 1
    // route 1: 0 -> 1 -> 3 -> 6 -> 0
    // route 2: 0 -> 2 -> 7 -> 0
    // route 3: 0 -> 9 -> 4 -> 8 -> 5 ->0
    // cách 2
    // route 1: 0 -> 2 -> 7 -> 0
    // route 2: 0 -> 9 -> 4 -> 8 -> 5 ->0
    // route 3: 0 -> 1 -> 3 -> 6 -> 0
    // thực chất cách 1 và 2 là một 
    // do đó để không lặp ta quy ước
    // 1 <= y[1] < y[2] < ... < y[K] <= n
    // tức là điểm xuất phát của route 1 luôn là khách hàng có chỉ số i nhỏ hơn điểm xuất phát của route 2
    // điểm xuất phát của route 2 lại nhỏ hơn route 3 ...
    // chặn 1 và n ở đầu cuối là vì có n khách hàng được đánh chỉ số từ (1 tới n)
    if (checkY(v, k)) // kiểm tra xem nếu khách hàng đầu mà yêu cầu quá với tải trọng xe thì cho fail 
    { // mà t đoán chắc ko cần hàm này vì nếu fail 1 xe -> fail all xe -> không có đáp án 
      // bonus thêm tại sao không cần check visited chưa
      // bởi vì trước lúc xác định các điểm trong 1 route thì ta buộc phải xác định điểm đầu các route trước 
      // rồi từ đó còn dư điểm nào thì điểm đó mới được dùng để phát triển nhánh cho route sau
      y[k] = v;
      visited[v] = true;
      load[k] = load[k] + d[v];
      f = f + c[0][v];
      nbSegments += 1;
      if (k == K)
      {
        TryX(y[1], 1); 
        // kiểu đủ nguyên liệu là các điểm đầu của route rồi thì bắt đầu duyệt tất từ route 1
        // duyệt hết route 1 rồi (kiểu gì chả tới 1 lúc nào đó max tải trọng) thì còn dư điểm nào thì duyệt route 2, ... n
        // do đó ta mới để đầu vào hàm TryX là y[1] (điểm đầu tiên của route 1) và 1 (k = 1 là báo hiệu route 1)
        // sau đó cần duyệt route nào tiếp thì trong hàm TryX kiểu gì cũng có TryX(y[k + 1], k + 1)
      }
      else
      {
        TryY(k + 1);
        // chưa chuẩn bị đủ cho all route thì chuẩn bị tiếp thôi
      }
      // phục hồi trạng thái
      visited[v] = false;
      nbSegments -= 1;
      f -= c[0][v];
      load[k] -= d[v];
    }
  }
}



int main()
{
  input();
  for (int v = 1; v <= n; v++) visited[v] = false;
  for (int k = 1; k <= K; k++) load[k] = 0;
  f = 0; f_min = 1e9;
  nbSegments = 0;
  y[0] = 0;
  /*
  for (int i = 1; i <= n; i++) cout << d[i] << " ";
  for (int i = 0; i <= n; i++)
  {
    cout << endl;
    for (int j = 0; j <= n; j++)
    {
      cout << c[i][j] << " ";
    }
  }
  */
  TryY(1);
  cout << f_min;
  return 0; 
}