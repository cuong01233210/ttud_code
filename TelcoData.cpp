
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int hople = 1;
map <string, int> so_cuoc_goi_bd;
int tong_so_cuoc_goi = 0;
map <string, int> tong_time_call;
bool checkPhone(string s)
{
  if (s.length() != 10) return false;
  for (int i = 0; i < s.length(); i++)
  {
    if (!(s[i] >= '0' && s[i] <= '9')) return false;
  }
  return true;
}
int countTime(string ftime, string etime)
{
  int startTime = 3600 *  ((ftime[0] - '0') * 10 + (ftime[1] - '0') ) + 60 * ( (ftime[3] - '0') * 10 + (ftime[4] - '0') ) +
  (ftime[6] - '0') * 10 + (ftime[7] - '0');
  int endTime = 3600 *  ((etime[0] - '0') * 10 + (etime[1] - '0') ) + 60 * ( (etime[3] - '0') * 10 + (etime[4] - '0') ) +
  (etime[6] - '0') * 10 + (etime[7] - '0');
  return endTime - startTime;
}
int main()
{
  string input;
  cin >> input;
  string start_number;
    string end_number;
    string date;
    string time_start;
    string time_end;
   // char * p_start;
   // char * p_end;
   

   
  while (strcmp(input.c_str(), "call") == 0)
  {
    cin >> start_number >> end_number >> date >> time_start >> time_end >> input;   
   // p_start = strtok(time_start, ":");
   // p_end = strtok(time_end, ":");
    tong_time_call[start_number] += countTime(time_start, time_end);
    if (checkPhone(start_number) == false || checkPhone(end_number) == false)
    {
      hople = 0;
    }
    so_cuoc_goi_bd[start_number]++;
    tong_so_cuoc_goi++;
  }
  do 
  {
    cin >> input;
    if (strcmp(input.c_str(), "?check_phone_number") == 0) 
    {
      if (hople == 1) cout << "1\n";
      else cout << "0\n";
    }
    if (strcmp(input.c_str(), "?number_calls_from") == 0)
    {
      cin >> input;
      cout << so_cuoc_goi_bd[input] << endl;
    }
    if (strcmp(input.c_str(), "?number_total_calls") == 0)
    {
      cout << tong_so_cuoc_goi << endl;
    }
    if (strcmp(input.c_str(), "?count_time_calls_from") == 0)
    {
      cin >> input;
      cout << tong_time_call[input] << endl;
    }
  } while (strcmp(input.c_str(), "#") != 0);
 //  cout << p_end << " " << p_start << endl;
  
}