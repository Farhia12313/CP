#include<bits/stdc++.h>
using namespace std;
void primeFactor(int n){
    while(n % 2 == 0){
        cout << 2 << endl;
        n /= 2;
    }
    for(int i = 3; i*i <= n;i += 2){
        while( n % i == 1) {
            cout << i << endl;
            n /= i;
        }
    }
    if(n > 2){
        cout << n <<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    primeFactor(num);
    return 0;
}