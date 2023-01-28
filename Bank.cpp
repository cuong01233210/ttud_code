#include <bits/stdc++.h>
using namespace std;




long total_transaction = 0;
long total_money_transaction = 0;
map <string , long> list_stored;
map <string , long> money_transaction_from_account;
map <string, long> inspect_cycle;




int main()
{
  string input = ".";
  string from_account;
  string to_account;
  long money;
  string time_point;
  string atm;

  cin >> from_account;
  do 
  {
    cin >>  to_account >> money >> time_point >> atm;
    total_transaction += 1;
    total_money_transaction += money;
    list_stored[from_account]++;
    list_stored[to_account]++;
    money_transaction_from_account[from_account] += money;
    inspect_cycle[from_account]++;
    cin >> from_account;
  } while (strcmp(from_account.c_str(), "#") != 0);

  
  do
  {
    cin >> input;
   
    if (strcmp(input.c_str(), "?number_transactions") == 0)
    {
      cout << total_transaction << endl;
    }
    if (strcmp(input.c_str(), "?total_money_transaction") == 0)
    {
      cout << total_money_transaction << endl;
    }
    if (strcmp(input.c_str(), "?list_sorted_accounts") == 0)
    {
        for (auto& it : list_stored)
      {
        cout << it.first << " ";
      }
        cout << endl;
    }
    if (strcmp(input.c_str(), "?total_money_transaction_from") == 0)
    {
      cin >> from_account;
      cout << money_transaction_from_account[from_account] << endl;
    }
    if (strcmp(input.c_str(), "?inspect_cycle") == 0)
    {
      cin >> from_account;
      long temp;
      cin >> temp;
      if (inspect_cycle[from_account] == temp) cout << "1" << endl;
      else cout << "0" << endl;
    }
    
  } while (strcmp(input.c_str(), "#") != 0);
  
  

}

/*
  cout << total_transaction << endl;
  cout << total_money_transaction << endl;
  for (auto& it : list_stored)
  {
    cout << it.first << " ";
  }
  cout << endl;
  cout << total_money_transaction["T000010010"];
*/
/*
  T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?number_transactions
?total_money_transaction
?list_sorted_accounts
?total_money_transaction_from T000010010
?inspect_cycle T000010010 3
#
*/