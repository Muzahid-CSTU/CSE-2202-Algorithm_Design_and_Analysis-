#include<bits/stdc++.h>
using namespace std;

int CSS(int ar[], int l, int m, int r){
    int left_sum = INT_MIN, sum = 0;
    for(int i = m; i >= l; i--){
        sum += ar[i];
        left_sum = max(left_sum, sum);
    }

    int right_sum = INT_MIN;
    sum = 0;
    for(int i = m + 1; i <= r; i++){
        sum += ar[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}


int MSS(int ar[],int l,int r){
    if(l == r){
        return ar[l];
    }

    int m = l + (r-l)/2;

    int lss = MSS(ar,l,m);
    int rss = MSS(ar,m+1,r);

    int css = CSS(ar,l,m,r);

    return max({lss,rss,css}); 
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }

    int ans = MSS(ar,0,n-1);
    
    cout << ans << endl;
}