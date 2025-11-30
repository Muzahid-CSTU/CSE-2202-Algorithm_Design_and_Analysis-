#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[12] = {5,6,1,9,3,7,2,11,4,10,8,12};

    for(int i=0;i<11;i++){
        for(int j=i+1;j<12;j++){
            if(ar[i] > ar[j]){
                int tmp = ar[i];
                ar[i] = ar[j];
                ar[j] = tmp;
            }
        }
    }

    for(int i=0;i<11;i++){
        cout << ar[i] << " ";
    }
}