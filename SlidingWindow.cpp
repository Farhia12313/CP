#include<bits/stdc++.h>
using namespace std;
int solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int w;
    cin >> w;
    int c =0;
    for(int i=0;i<w;i++){
        c += arr[i];
    }
    int max = c;
    for(int i=1;i <= n-w;i++){
        c = c - arr[i-1]+arr[i+w-1];
        if(c > max){
            max = c;
        }    
    }
    return max;
}
int main(){
    int t;
    cin >> t;
    while(t--){
      int res=  solve();
      cout << res << endl;
    } 
}