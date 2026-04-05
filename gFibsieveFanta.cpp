#include<bits/stdc++.h>
using namespace std;
void solve(int caseNum){
    long long s;
    if(!(cin >> s)) return;
    long long n = ceill(sqrtl((long double)s));
    long long mid = (n * n)-(n-1);
    long long x,y;
    if(s == mid){
        x=n;
        y=n;

    }
    else if(n%2 == 0){
        if(s < mid){
            x = s-(n-1 ) * (n-1);
            y = n;
        }
        else{
            x = n;
            y = n * n - s + 1;
        }
    }
    else{
        if(s < mid){
            x =  n;
            y = s - (n - 1) * (n - 1);
        }
        else{
            x = n * n - s + 1;
            y = n;
        }
    }
    cout <<"Case " << caseNum <<": "<<x<<" " <<y <<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if(cin >> t){
        for(int i=1;i<=t;i++){
        solve(i);
    }
    }
    
    return 0;
}