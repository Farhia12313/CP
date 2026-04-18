#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll bigMod(ll base,ll exp,ll mod){
    if(mod == 1) return 0;
    ll res = 1;
    base %= mod;
    while(exp > 0){
        if(exp % 2 == 1) {
            res = ( res * base) % mod;
        }
        base = ( base * base) % mod;
        exp /= 2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll b,p,m;
    while(cin >> b >> p >> m){
        cout << bigMod(b,p,m) << endl;
    }
    return 0;
}