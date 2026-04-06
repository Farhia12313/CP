#include<bits/stdc++.h>
using namespace std;
const int MAX = 20000000;
bool is_prime[MAX + 1];
vector<pair<int,int>>twin_primes;
void sieve(){
    for(int i=2;i<=MAX;i++) is_prime[i] = true;
    for(int p=2;p*p <= MAX; p++){
        if(is_prime[p]){
            for(int i = p*p;i <= MAX; i += p)
            is_prime[i] = false;
        }
    }
    for(int i = 3;i <= MAX-2;i++){
        if(is_prime[i] && is_prime[i + 2]){
             twin_primes.push_back({i,i+2});
             if(twin_primes.size() == 100000) break;
    
        }
       
    
}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int s;
    while(cin >> s){
        if(s<=twin_primes.size()){
            cout <<"(" << twin_primes[s-1].first <<", " << twin_primes[s -1].second << ")" << endl;
        }
    }
    return 0;

}