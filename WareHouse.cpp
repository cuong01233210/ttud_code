#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int n,f[N][102],T,D,a[N],t[N],res;
// Gọi f[i][k] là số lượng hàng lớn nhất có thể lấy được nếu chỉ xét những nhà kho từ 1 -> i – 1,
// lấy nhà kho thứ i và thời gian lấy hàng không vượt quá k.​


void inp(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> T>>D;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>> t[i];
}

void proc(){
  // ý tưởng bài này là 
  // tính được khối lượng đào được tại bãi i thông qua các bãi i - D, ,.... i - 1
  // làm sao để tính được khi ta lo về vấn đề time, rõ ràng phải phân chia để tối ưu time và năng suất quá khó
  // không, ta ko cần care vấn đề đó, chính xác là ta cũng vét cạn
  // nhưng dùng vét cạn version 2 là quy hoạch động,
  // kiểu đệ quy là tính i = 2 và i = 2 thì ta cần tính i = 1 i = 2 và ghi nhan xong lại tính lại i = 1 i = 2 i =3
  // -> lặp phép tính quá nhiều
  // -> thay vì làm thế, ta dùng quy hoạch động tính i = 1 -> lưu -> tính i = 2 -> lưu -> tính i = 3
  // -> số phép tính giảm đi rất nhiều

  // nhưng nói thì dễ, code mới khó -> h ta cùng phân tích từng dòng code để hiểu hơn
  // đầu tiên là vòng for i 1 -> n thì như phân tích ở trên tính dần i = 1 rồi i = 2 ,...
  // tiếp đến là k = t[i] -> T
  // k ở đây ta cần là thời gian tối thiểu để lấy được chính cái i đó 
  // (chứ nếu chính nhà kho i mà không khai thác xong thì đòi khai thác những chỗ i - D tới i - 1 sao)
  // cận trên là T là max time mà ta có thể dùng là hợp lý r
  // còn vòng for j từ max(0, i - D) -> i - 1 thì sao
  // thực ra chính là cái trò tính i thông qua i - D tới i - 1
  // max (0, i - D) là để counter khi i < D, ví dụ i = 1, D = 2 , 
  // lúc này ta có thể ngầm hiểu có thể tính i = 1 thông qua i = -1 và i = 0
  // chú ý là ta tính tất chứ không chọn cái nào có lợi hơn, việc chọn cái nào có hơn tính sau
  // bước chọn con đường nào lợi hơn là ở bước f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
  // chú ý là hiện tại k cố định, tức là xét cùng 1 mức time k được cấp, 
  // thì sản lượng cái nào ngon hơn thông qua các cái trước thì lấy
  // và tất nhiên cùng 1 i thì có thể có nhiều trường hợp
  // hoặc là cùng k, hoặc là khác k
  // ví dụ N = 4, T = 3, D = 3
  // a[N] = 5 4 9 3      
  // t[N] = 2 1 1 1
  // lúc này ta quan sát thử cùng 1 i = 4 sẽ có 3 sắc thái
  // f[4][1] chỉ đủ lo cho thân nó là 3
  // f[4][2] có thể là 3 + 4 (j = 4 - 2 = 2) hoặc 3 + 9 (j = 4 - 1 = 3) tất nhiên đều dùng chung k = 2
  // f[4][3] có thể là 3 + 5 (j = 4 - 3 = 1) hoặc 3 + (9 + 4) (lúc này sẽ có bản fusion của 4 và 9 vào i = 3 từ trước đó)
  // tóm lại là sau khi tính xong ta sẽ có tất cả các giá trị ta cần
  // (sẽ tìm được max luôn tại điểm thời gian k cố định và i cố định như dòng code  f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);)
  // cuối cùng là dòng res = max(res, f[i][k]); 
  // cái này quá đơn giản r, so sánh mỗi điểm i, k tìm được với max, nếu max < điểm i, k thì lấy giá trị max = i, k
    for (int i = 1; i <= n; i++)
    {
      for (int k = t[i]; k <= T; k++)
      {
        for (int j = max(0, i - D); j <= i - 1; j++)
        {
          f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
        }
        res = max(res, f[i][k]);
      }
    }
    cout << res;
}

int main(){
    inp();
   //cout << f[100][100];
    proc();
}


// dưới đây là test case và các giá trị in ra tại các mốc i, k chi tiết để hiểu bài hơn

/*
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2

i: 1 k: 1 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 1 k: 2 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 1 k: 3 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 1 k: 4 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 1 k: 5 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 1 k: 6 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 2 k: 2 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 8 f[i][k]sau: 8

i: 2 k: 2 j: 1
f[i][k]trc: 8 f[j][k-t[i]]: 0 a[i]: 8 f[i][k]sau: 8

i: 2 k: 3 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 8 f[i][k]sau: 8

i: 2 k: 3 j: 1
f[i][k]trc: 8 f[j][k-t[i]]: 6 a[i]: 8 f[i][k]sau: 14

i: 2 k: 4 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 8 f[i][k]sau: 8

i: 2 k: 4 j: 1
f[i][k]trc: 8 f[j][k-t[i]]: 6 a[i]: 8 f[i][k]sau: 14

i: 2 k: 5 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 8 f[i][k]sau: 8

i: 2 k: 5 j: 1
f[i][k]trc: 8 f[j][k-t[i]]: 6 a[i]: 8 f[i][k]sau: 14

i: 2 k: 6 j: 0
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 8 f[i][k]sau: 8

i: 2 k: 6 j: 1
f[i][k]trc: 8 f[j][k-t[i]]: 6 a[i]: 8 f[i][k]sau: 14

i: 3 k: 2 j: 1
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 5 f[i][k]sau: 5

i: 3 k: 2 j: 2
f[i][k]trc: 5 f[j][k-t[i]]: 0 a[i]: 5 f[i][k]sau: 5

i: 3 k: 3 j: 1
f[i][k]trc: 0 f[j][k-t[i]]: 6 a[i]: 5 f[i][k]sau: 11

i: 3 k: 3 j: 2
f[i][k]trc: 11 f[j][k-t[i]]: 0 a[i]: 5 f[i][k]sau: 11

i: 3 k: 4 j: 1
f[i][k]trc: 0 f[j][k-t[i]]: 6 a[i]: 5 f[i][k]sau: 11

i: 3 k: 4 j: 2
f[i][k]trc: 11 f[j][k-t[i]]: 8 a[i]: 5 f[i][k]sau: 13

i: 3 k: 5 j: 1
f[i][k]trc: 0 f[j][k-t[i]]: 6 a[i]: 5 f[i][k]sau: 11

i: 3 k: 5 j: 2
f[i][k]trc: 11 f[j][k-t[i]]: 14 a[i]: 5 f[i][k]sau: 19

i: 3 k: 6 j: 1
f[i][k]trc: 0 f[j][k-t[i]]: 6 a[i]: 5 f[i][k]sau: 11

i: 3 k: 6 j: 2
f[i][k]trc: 11 f[j][k-t[i]]: 14 a[i]: 5 f[i][k]sau: 19

i: 4 k: 3 j: 2
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 10 f[i][k]sau: 10

i: 4 k: 3 j: 3
f[i][k]trc: 10 f[j][k-t[i]]: 0 a[i]: 10 f[i][k]sau: 10

i: 4 k: 4 j: 2
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 10 f[i][k]sau: 10

i: 4 k: 4 j: 3
f[i][k]trc: 10 f[j][k-t[i]]: 0 a[i]: 10 f[i][k]sau: 10

i: 4 k: 5 j: 2
f[i][k]trc: 0 f[j][k-t[i]]: 8 a[i]: 10 f[i][k]sau: 18

i: 4 k: 5 j: 3
f[i][k]trc: 18 f[j][k-t[i]]: 5 a[i]: 10 f[i][k]sau: 18

i: 4 k: 6 j: 2
f[i][k]trc: 0 f[j][k-t[i]]: 14 a[i]: 10 f[i][k]sau: 24

i: 4 k: 6 j: 3
f[i][k]trc: 24 f[j][k-t[i]]: 11 a[i]: 10 f[i][k]sau: 24

i: 5 k: 3 j: 3
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 11 f[i][k]sau: 11

i: 5 k: 3 j: 4
f[i][k]trc: 11 f[j][k-t[i]]: 0 a[i]: 11 f[i][k]sau: 11

i: 5 k: 4 j: 3
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 11 f[i][k]sau: 11

i: 5 k: 4 j: 4
f[i][k]trc: 11 f[j][k-t[i]]: 0 a[i]: 11 f[i][k]sau: 11

i: 5 k: 5 j: 3
f[i][k]trc: 0 f[j][k-t[i]]: 5 a[i]: 11 f[i][k]sau: 16

i: 5 k: 5 j: 4
f[i][k]trc: 16 f[j][k-t[i]]: 0 a[i]: 11 f[i][k]sau: 16

i: 5 k: 6 j: 3
f[i][k]trc: 0 f[j][k-t[i]]: 11 a[i]: 11 f[i][k]sau: 22

i: 5 k: 6 j: 4
f[i][k]trc: 22 f[j][k-t[i]]: 10 a[i]: 11 f[i][k]sau: 22

i: 6 k: 2 j: 4
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 6 k: 2 j: 5
f[i][k]trc: 6 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 6 k: 3 j: 4
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 6 k: 3 j: 5
f[i][k]trc: 6 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 6 k: 4 j: 4
f[i][k]trc: 0 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 6 k: 4 j: 5
f[i][k]trc: 6 f[j][k-t[i]]: 0 a[i]: 6 f[i][k]sau: 6

i: 6 k: 5 j: 4
f[i][k]trc: 0 f[j][k-t[i]]: 10 a[i]: 6 f[i][k]sau: 16

i: 6 k: 5 j: 5
f[i][k]trc: 16 f[j][k-t[i]]: 11 a[i]: 6 f[i][k]sau: 17

i: 6 k: 6 j: 4
f[i][k]trc: 0 f[j][k-t[i]]: 10 a[i]: 6 f[i][k]sau: 16

i: 6 k: 6 j: 5
f[i][k]trc: 16 f[j][k-t[i]]: 11 a[i]: 6 f[i][k]sau: 17
24%                                          
(base) macbookpro@MacBook-Pro-cua-Macbook-2 ttud_code % 
*/