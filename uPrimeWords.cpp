#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n){
    if(n == 1) return true;
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i*i <= n;i += 2){
        if(n % i == 0) return false;
    }
    return true;

}
int getCharValue(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a' + 1;
    }
    else if(c >= 'A' && c <= 'Z'){
        return c - 'A' + 27;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
        int totalSum =  0;
        for(char c : s){
            totalSum += getCharValue(c);
        }
        if(is_prime(totalSum)){
            cout <<"It is a prime word."<<endl;
        }
        else{
            cout <<"It is not a prime word."<<endl;
        }
    }
return 0;
}