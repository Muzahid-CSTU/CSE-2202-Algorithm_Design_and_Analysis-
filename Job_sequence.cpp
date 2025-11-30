#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>, int> &a,
         pair<pair<int,int>, int> &b)
{
    return a.first.first > b.first.first;  
}

int main() {
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> jobs;
    for(int i = 0; i < n; i++){
        int profit, deadline;
        cin >> profit >> deadline;
        jobs.push_back({{profit, deadline}, i+1});
    }
    sort(jobs.begin(), jobs.end(), cmp);
    int maxDeadline = 0;
    for(auto &j : jobs){
        maxDeadline = max(maxDeadline, j.first.second);
    }
    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;
    vector<int> selected;
    for(auto &job : jobs){
        int profit = job.first.first;
        int deadline = job.first.second;
        int id = job.second;
        for(int t = deadline; t >= 1; t--){
            if(slot[t] == -1){
                slot[t] = id; 
                totalProfit += profit;
                selected.push_back(id);
                break;
            }
        }
    }
    cout << "Maximum Profit: " << totalProfit << "\n";
    cout << "Jobs selected: ";
    for(int x : selected){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
