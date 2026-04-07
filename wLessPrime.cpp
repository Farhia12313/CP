#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
bool is_prime[maxn + 1];
void sieve(){
    for(int i=2;i <= maxn;i++) is_prime[i] = true;
    for(int p=2;p * p <= maxn;p++){
        if(is_prime[p]){
            for(int i = p * p; i <= maxn; i += p)
            is_prime[i] = false;
        }
    }
}
void solve(){
    int n;
    cin >> n;
    int max_rem = -1;
    int best_x = -1;
    for(int x=2;x <= n;x++){
        if(is_prime[x]){
            int rem = n % x;
            if(rem > max_rem){
                max_rem = rem;
                best_x = x;
            }
        }
    }
    cout << best_x << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int m;
    if(cin >> m){
        while(m--){
            solve();
        }
    }
    return 0;
}