#include<bits/stdc++.h>
using namespace std;

void merge(int ar[], int l, int m,int r){
    cout << l << " " << r << endl;
    int ls = m-l+1;
    int rs = r-m;
    int la[ls], ra[rs];
    int k = 0;

    for(int i=l;i<=m;i++){
        la[k] = ar[i];
        k++;
    }
    k = 0;
    for(int i=m+1;i<=r;i++){
        ra[k] = ar[i];
        k++;
    }
    int i=0,j=0;
    int cur = l;

    while(i<ls && j<rs){
        if(la[i] <= ra[j]){
            ar[cur] = la[i];
            i++;
        }
        else{
            ar[cur] = ra[j];
            j++;
        }

        cur++;
    }

    while(i<ls){
        ar[cur] = la[i];
        i++;cur++;
    }

    while(j<rs){
        ar[cur] = ra[j];
        j++;cur++;
    }

}

void merge_sort(int ar[],int l,int r){
    if(l<r){

        int m = l + (r-l)/2;
        merge_sort(ar,l,m);
        merge_sort(ar,m+1,r);

        merge(ar,l,m,r);
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }
    int mid = n/2;
    merge_sort(ar,0,n-1);
    for(int i=0;i<n;i++){
        cout << ar[i] << " ";
    }
}
