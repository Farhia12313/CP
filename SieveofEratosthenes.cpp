#include<bits/stdc++.h>
using namespace std;
void sieve(int n){
    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false;
    for(int p=2;p*p <= n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i += p){
                prime[i] =  false;
            }
        }
    }
    for(int p=2;p <= n; p++){
        if(prime[p]){
            cout << p <<" "; 
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >>n;
    sieve(n);
    return 0;
}