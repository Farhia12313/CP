#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    if(!(cin >> n)) return 0;
    ll fact = 1;
    bool lessThanFourDigit = true;
    for(int i=1;i <= n;i++){
        fact *= i;
        if(fact >= 10000){
            lessThanFourDigit = false;
            fact %= 10000;
        }
    }
    if(lessThanFourDigit){
        cout << fact <<endl;
    }
    else{
        if(fact < 1000) cout <<"0";
        if(fact < 100) cout <<"0";
        if(fact < 10) cout <<"0";
        cout << fact << endl;
    }
    return 0;
}