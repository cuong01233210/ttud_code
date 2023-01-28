#include <bits/stdc++.h>

using namespace std;

// <from_account> <to_account> <money> <time_point> <atm>

map<string, int> accTotalTrans;
map<string, vector<string>> accSequence;
// vector<vector<string>> accSequence;
vector<string> currentTrack;
int totalTrans = 0;
int totalMoney = 0;
int checkTransCycle; // use to check if there is a transaction cycle of length k
string type = "";
string facc, tacc, transTime, id;
int amount;

bool stringCompare(string a, string b)
{
    return a.compare(b) < 0;
}

void Try(int t, int k, string currentKey, string startingAcc)
{
    if (t != k)
    {
        for (int i = 0; i < accSequence[currentKey].size(); ++i)
        {
            if (accTotalTrans[accSequence[currentKey][i]] == 0 || accSequence[currentKey][i] == startingAcc || find(currentTrack.begin(), currentTrack.end(), accSequence[currentKey][i]) != currentTrack.end())
            {
                continue;
            }
            else
            {
                currentTrack.push_back(accSequence[currentKey][i]);
                Try(t + 1, k, accSequence[currentKey][i], startingAcc);
                currentTrack.pop_back();
            }
        }
    }
    else
    {
        // cout << currentKey << endl;
        if (find(accSequence[currentKey].begin(), accSequence[currentKey].end(), startingAcc) != accSequence[currentKey].end())
        {
            // for (int i = 0; i < currentTrack.size(); ++i) {
            //     cout << currentTrack[i] << " ";
            // } cout << endl;
            checkTransCycle = 1;
            return;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input part
    do
    {
        cin >> facc;
        if (facc == "#")
        {
            continue;
        }
        totalTrans++;
        cin >> tacc >> amount >> transTime >> id;
        totalMoney += amount;
        accTotalTrans[facc] += amount;
        accTotalTrans[tacc] += 0;
        if (accSequence[facc].size() != 0)
        {
            if (find(accSequence[facc].begin(), accSequence[facc].end(), tacc) == accSequence[facc].end())
            {
                accSequence[facc].push_back(tacc);
            }
        }
        else
            accSequence[facc].push_back(tacc);
    } while (facc != "#");



// Query part
    do
    {
        cin >> type;
        if (type == "#")
            continue;
        if (type == "?number_transactions")
        {
            cout << totalTrans << endl;
        }
        else if (type == "?total_money_transaction")
        {
            cout << totalMoney << endl;
        }
        else if (type == "?list_sorted_accounts")
        {
            for (auto &acc : accTotalTrans)
            {
                cout << acc.first << " ";
            }
            cout << endl;
        }
        else if (type == "?total_money_transaction_from")
        {
            string accToCheck;
            cin >> accToCheck;
            cout << accTotalTrans[accToCheck] << endl;
        }
        else if (type == "?inspect_cycle")
        {
            checkTransCycle = 0;
            string startingAcc;
            int k;
            cin >> startingAcc >> k;
            Try(1, k, startingAcc, startingAcc);
            currentTrack.clear();
            cout << checkTransCycle << endl;
        }
    } while (type != "#");
    return 0;
}














