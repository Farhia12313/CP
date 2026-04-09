#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    for(int a = 0; a <= 10; a++){
        int b = n - a;
        if(b >= 0 && b <= 10){
            cout << a << " "<< b << endl;
            return ;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
