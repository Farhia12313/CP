#include<bits/stdc++.h>
using namespace std;
void factorize(long long n){
    long long original = n;
    cout << original << " = ";
     if (n < 0) {
        cout << "-1 x ";
        n = -n; 
    }
 vector<long long> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i];
        if (i < factors.size() - 1) {
            cout << " x ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long g;
    while (cin >> g && g != 0) {
        factorize(g);
    }

    return 0;
}