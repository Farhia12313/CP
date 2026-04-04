#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    if(!(cin>>N)) return 0;
    if(N==1 || N==2){
        cout << 1 << endl;
        return 0;

    }
    long long a=1;
    long long b=1;
    long long current = 0;
    for(int i=3;i<=N;++i){
        current = a+b;

        a=b;
        b=current;
    }
    cout << b << endl;
}