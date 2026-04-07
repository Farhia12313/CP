#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
bool is_prime[ MAX + 1];
void sieve(){
    fill(is_prime,is_prime +MAX + 1,true);
    is_prime[0] = is_prime[1] = false;
    for(int p = 2; p*p <= MAX;p++){
        if(is_prime[p]){
            for(int i = p*p;i <= MAX;i +=p) is_prime[i] = false;
        }
    }

}
int revnum(int n){
    int rev = 0;
    while(n > 0){
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    while(cin >> n){
        if(!is_prime[n]){
            cout << n << " is not prime." << endl;
        }
        else{
            int reversedn = revnum(n);
            if(reversedn != n && reversedn <= MAX && is_prime[reversedn]){
                cout << n <<" is emirp." << endl;
            }
            else{
               cout << n <<" is prime." << endl; 
            }
        }
    }
    return 0;
}