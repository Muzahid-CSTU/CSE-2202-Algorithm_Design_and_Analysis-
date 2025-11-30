#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> v;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({{e, s}, i + 1});
    }
    sort(v.begin(), v.end());
    vector<int> slctd;
    slctd.push_back(v[0].second);
    int lastEnd = v[0].first.first;
    for (int i = 1; i < n; i++) {
        int curS = v[i].first.second;
        int curF = v[i].first.first;

        if (curS >= lastEnd) {
            slctd.push_back(v[i].second);
            lastEnd = curF;
        }
    }
    cout << slctd.size() << endl;
    for (int x : slctd){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
