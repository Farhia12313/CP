#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll power(ll base,ll exp,ll mod){
ll res = 1;
base %= mod; 
while(exp > 0){
    if(exp % 2 == 1) res = ( res * base) % mod;
    base = ( base * base) % mod;
    exp /= 2;
}
return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    while(cin >> a >> b){
        ll result = power(a,b,100);
        cout <<result<<endl;
    }
    return 0;
}
