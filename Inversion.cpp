#include <bits/stdc++.h>
using namespace std;
#define MOD int(1e9 + 7)
int a[1000002];
int n;

// i đánh dấu phần tử left của đoạn [left, right] nào đó của mảng a -> mid
  // j đánh dấu phần tử từ mid của a tới right
  // k đánh dấu phần tử của mảng temp, dùng để duyệt mảng temp từ vị trí left tới right

  // ví dụ
  // mảng a có 8 phần tử từ a[1] -> a[8]
  // do đó mảng temp có thể được hợp thể từ 2 mảng a[1 -> 4] và a[5 -> 8]
  // thì trong trường hợp này left = 1, right = 8, mid = 5
  // và có thể fusion thành mảng temp như đoạn code trên
  // hay bé hơp là mảng a[1->4] được hợp thể từ a[1->2] và a[3->4]
  // cứ mỗi bước hợp thể thì ta cần reset lại thứ tự từ bé đến lớn bằng cách tạo mảng temp 
  // và duyệt so sánh 2 nửa của mảng con, cái nào ăn thì sắp lên trước
  // do đó cuối cùng ta cần sao chép lại đoạn đã hợp thể lại vào a
  // ex mảng a có giá trị 2 1 4 5 0 8 9 2
  // phân tách được 8 mảng con [2] [1] [4] [5] [7] [8] [9] [2]

  // bước 1: fusion 2 mảng 1 ptu thành 1 mảng 2 ptu
  // -> temp[1->2] = fusion của [2] và [1] (left 1, right 2, mid 2)
  // temp[1 -> 2] = [1 2] inv_count = 0 + 1 = 1 (có inv)
  // lúc này mảng a [1 2 4 5 0 8 9 2]
  // temp[3->4] = fusion của a[3] = 4 và a[4] = 5
  // temp[3->4] = [4 5] inv_count = 1 (không có inv)
  // -> a = [1 2 4 5 0 8 9 2]
  // temp[5 -> 6] = fusion của a[5] = 0 và a[6] = 8
  // temp[5 -> 6] = [0 8] và inv_count = 1 (ko có inv)
  // -> a = [1 2 4 5 0 8 9 2]
  // temp[7 -> 8] = fusion của a[7] = 9 và a[8] = 2
  // temp[7 -> 8] = [2 9] và inv_count = 2 (có inv)
  // a = [1 2 4 5 0 8 2 9]

  // bước 2: fusion 2 mảng 2 ptu thành 1 mảng 4 ptu
  // tạm hiểu mảng a thành al (a left) và ar (a right)
  // temp[1 -> 4] = fusion của a[1 -> 2] (al) và a[3->4] (ar)
  // biến đếm left = 1, mid = 3 right = 4
int _merge(int left, int mid, int right)
{
  int i = left, j = mid, k = left;
  int inv_count = 0;
  int temp[1000002];
  while ((i <= mid - 1) && (j <= right))
  {
    if (a[i] <= a[j])
    {
      temp[k++] = a[i++];
    }
    else
    {
      temp[k++] = a[j++];
      // phần tử bên phải nhỏ hơn -> inversion
      // ex dãy trái al = [2 4 5 6 7]
      // dãy phải 3 .... ar
      // xét tại điểm al[2] = 4 > ar[1] = 3
      // -> dễ thấy các điểm al[3] -> al[5] = 5 6 7 cũng lớn hơn ar[1] = 3
      // -> thay vì cộng 1 ta phải cộng 4
      inv_count = ((mid - i) + inv_count) % MOD;
    }
  }
  // copy nốt phần dư của mảng bên trái vào temp nếu có
  while (i <= mid - 1) temp[k++] = a[i++];
  // copy nốt phần dư của mảng bên phải vào temp nếu có
  while (j <= right) temp[k++] = a[j++];

  // copy lại mảng temp vào mảng a
  for (i = left; i <= right; i++)
  {
    a[i] = temp[i];
  }
  return inv_count;
}
int mergeSort(int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    mid = (left + right) / 2;
    //cout << endl << left << " " << right << " " << mid ;
    inv_count = (mergeSort(left, mid) % MOD + inv_count) % MOD;
    inv_count = (mergeSort(mid + 1, right) % MOD + inv_count) % MOD;
    inv_count = (inv_count + _merge(left, mid + 1, right) % MOD) % MOD;
  }
  return inv_count;
}


int main()
{
  ios_base :: sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
  }
  cout << mergeSort(1, n) << endl;
  //for (int i = 1; i <= n; i++) cout << a[i] << " ";
}


/*
6
3 2 4 5 6 1
*/



