#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> add(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

vector<vector<int>> sub(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] - b[i][j];
    return c;
}

vector<vector<int>> mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size();
    if (n == 1) return {{a[0][0] * b[0][0]}};

    int m = n / 2;
    vector<vector<int>> a11(m, vector<int>(m)), a12(m, vector<int>(m)), a21(m, vector<int>(m)), a22(m, vector<int>(m));
    vector<vector<int>> b11(m, vector<int>(m)), b12(m, vector<int>(m)), b21(m, vector<int>(m)), b22(m, vector<int>(m));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            a11[i][j] = a[i][j]; a12[i][j] = a[i][j+m];
            a21[i][j] = a[i+m][j]; a22[i][j] = a[i+m][j+m];

            b11[i][j] = b[i][j]; b12[i][j] = b[i][j+m];
            b21[i][j] = b[i+m][j]; b22[i][j] = b[i+m][j+m];
        }

    auto p1 = mul(add(a11,a22), add(b11,b22));
    auto p2 = mul(add(a21,a22), b11);
    auto p3 = mul(a11, sub(b12,b22));
    auto p4 = mul(a22, sub(b21,b11));
    auto p5 = mul(add(a11,a12), b22);
    auto p6 = mul(sub(a21,a11), add(b11,b12));
    auto p7 = mul(sub(a12,a22), add(b21,b22));

    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            c[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
            c[i][j+m] = p3[i][j] + p5[i][j];
            c[i+m][j] = p2[i][j] + p4[i][j];
            c[i+m][j+m] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
        }
    return c;
}

void prt(const vector<vector<int>> &v) {
    for (auto &r : v){ 
        for (auto x : r){
            cout << x << " ";
        }
        cout << "\n"; 
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    for (auto &r : a){
        for (auto &x : r){ 
            cin >> x;
        }
    }
    for (auto &r : b){
        for (auto &x : r){
            cin >> x;
        }
    }

    auto c = mul(a,b);
    prt(c);
}
