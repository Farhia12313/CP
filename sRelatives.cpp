#include<bits/stdc++.h>
using namespace std;
long long phi(long long n){
    long long result = n;
    for(long long i=2;i*i <= n;i++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            result -= result / i;
        }
    }
    if(n > 1){
         result -= result / n;
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    while(cin >> n && n != 0){
        if(n == 1){
            cout << 0 << endl;
        }
        else{
            cout << phi(n) <<endl;
        }
    }
    return 0;
}