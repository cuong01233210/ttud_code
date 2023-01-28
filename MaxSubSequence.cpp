// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to print the maximum
// non-empty subsequence sum
vector <long> zero_for_one_level;
 vector <vector <long> > mang_luu_cac_tang;
 /*
 Ta sử dụng biến sum để giữ giá trị tổng tiềm năng của các phần tử liên tục phía trước (khi thêm tổng này vào đoạn mới phía sau ta luôn nhận được một đoạn có tổng lớn hơn). Ta nhận thấy khi giá trị của sum < 0 thì ta sẽ cập nhật lại giá trị sum = 0 (bỏ đi đoạn phía trước).
 */
long MaxNonEmpSubSeq(vector <long> a, long n)
{
    int maxsum = 0;
    int sum = 0;

for (int i = 0; i < n; ++i) {
sum += a[i];

if (sum < 0) sum = 0;

maxsum = max(sum, maxsum);

}
return maxsum;
}
 
// Driver Code
int main()
{
    long N;
    cin >> N;
    vector <long> arr;
    for (long i = 0; i < N; i++)
    {
      long temp;
      cin >> temp;
      arr.push_back(temp);
      zero_for_one_level.push_back(0);
    }
    
    cout << MaxNonEmpSubSeq(arr, N);
 
    return 0;
}
/*
10
3 -1 -3 5 2 5 0 -1 5 4
*/

/*

    // Traverse the array
    // arr has x phan tu -> have x mini level
    vector <long> save_max_each_level;
    save_max_each_level.push_back(max);
    //cout << "n: " << n;
   
    for (long k = 2; k <= n; k++)
    {
       long max_in_level = -1000;
        for(long i = 0; i < n; i++)
        {
            long temp = 0;
           // cout << "voi k la: " << k << endl;
            for (long j = i; j < i + k && j < n; j++)
            {           
                temp += a[j];
            }
          //  cout << temp << " ";
           // cout << endl;
            if (temp > max_in_level) max_in_level = temp;      
        }
        save_max_each_level.push_back(max_in_level);
    }
    */
    
   /*
    if (max < *max_element(mang_luu_cac_tang[lv].begin(), mang_luu_cac_tang[lv].end()))
        {
            max = *max_element(mang_luu_cac_tang[lv].begin(), mang_luu_cac_tang[lv].end());
        }
        */
