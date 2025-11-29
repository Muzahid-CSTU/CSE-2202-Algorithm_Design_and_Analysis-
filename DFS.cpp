#include<bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

void DFS(int src){
    cout << src << endl;
    vis[src] = true;
    for(int child : v[src]){
        if(vis[child] != true){
            DFS(child);
        }
    }
}

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;
    for(int i = 0; i <= 1005; i++){
        vis[i] = false;
    }
    DFS(src);
    return 0;
}